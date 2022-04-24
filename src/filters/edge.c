#include "filters.h"
#include "filters_internal.h"

void accentuateEdges (char* filename) {
    IMAGE img = readImg(filename);

    if (img.channelNumber >= 3) {
        applyGrayscale(filename);
        img = readImg("./processedImg.jpg");
    }

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

    for (int y=0; y<img.height *img.channelNumber; y++) {
        for (int x=0; x<img.width; x+=img.channelNumber) {
            int gradientX=0, gradientY=0;
            gradientX = getHorizontalGradient(img, y, x, kernelX);
        }
    }

    submitChanges(img);
    printf("Edges accentuated successfully.\n");
    free(img.data);
}