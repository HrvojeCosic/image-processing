#include "filters.h"
#include "filters_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include "../dimension_tools/dimension_tools.h"

void horizontalPixelSort(char* filename) {
    IMAGE img = readImg(filename);

    while (img.size > 1686000) { // number before stack overflow (on my pc) - 1000x562 rgb image
        IMAGE newProps = { img.data, img.size, (img.width / 2), img.height, img.channelNumber };
        printf("Image is too large, downsizing...\n");
        nearestNeighborResize(filename, newProps);

        char currentProcessedImgPath[100];
        sprintf(currentProcessedImgPath, "./%s", processedImgFilename);
        img = readImg(currentProcessedImgPath);
    } 

    quickSortPixels(img.data, 0, img.size, img.channelNumber);

    submitChanges(img);
    printf("Pixels sorted successfully.\n");
    free(img.data);
}