#include "filters.h"
#include "filters_internal.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void accentuateEdges (char* filename) {
    applyGrayscale(filename);
    char currentProcessedImgPath[100];
    sprintf(currentProcessedImgPath, "./%s", processedImgFilename);
    IMAGE img = readImg(currentProcessedImgPath);
    IMAGE imgCopy = readImg(currentProcessedImgPath);

    int kernelX[3][3] = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}
    };
    int kernelY[3][3] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    };

    for (int y=img.channelNumber; y<img.height * img.channelNumber; y++) {
        for (int x=0; x<img.width; x+=img.channelNumber) {
            int gradientX = getHorizontalGradient(img, y, x, kernelX);
            int gradientY = getVerticalGradient(img, y, x, kernelY);
            int totalGradient = sqrt( pow(gradientX, 2) + pow(gradientY, 2) );
            
            int ch = img.channelNumber;
            if (totalGradient > (int)255 / 2) {
                while(ch != 0) *(imgCopy.data + (img.width * y) + x + (--ch)) = 255;
            } else {
                while(ch != 0) *(imgCopy.data + (img.width * y) + x + (--ch)) = 0;
            }
        }
    }

    submitChanges(imgCopy);
    printf("Edges accentuated successfully.\n");
    free(img.data);
}