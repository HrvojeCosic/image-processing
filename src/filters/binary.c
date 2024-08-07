#include "../../include/filters.h"
#include "../../include/filters_internal.h"
#include <stdio.h>
#include <stdlib.h>

void applyBinary(char* filename) {
    IMAGE img = readImg(filename);

    if (img.channelNumber >= 3) {
        applyGrayscale(filename);
        char fixedImgFilename[102];
        sprintf(fixedImgFilename, "./%s", processedImgFilename);
        img = readImg(fixedImgFilename);
    }

    int threshold = computeThreshold(img);

    for (size_t i=0; i<img.size; i+=img.channelNumber) {
        int greyLvl = *(img.data+i);
        int finalPixel = greyLvl < threshold ? 0 : 255;

        for (size_t j=i; j < i+img.channelNumber; j++)
            *(img.data+j) = finalPixel;
    }

    submitChanges(img);
    printf("Binary filter applied successfully.\n");
    free(img.data);
}
