#include "filters.h"
#include "filters_internal.h"

IMAGE img;
void applyBoxBlur(char* filename) {
    img = readImg(filename);
    IMAGE newImg = readImg(filename);

    for (int y=0; y<img.height*img.channelNumber; y++) {
        for (int x=0; x<img.width; x++) {
            int newPixelValue = getNeighborSum((y * img.width) + x) / 9;
            newImg.data[y*img.width + x] = newPixelValue;
        }
    }

    submitChanges(newImg);
    printf("Image blurred (using box blur) successfully.\n");
    free(newImg.data);
    free(img.data);
    return;
}

double getNeighborSum(int centralPixel) {
    int neighborTop = centralPixel - img.width;
    int neighborLeft = centralPixel - img.channelNumber;
    int neighborTopLeft = neighborLeft - img.width;
    int neighborBottomLeft = neighborLeft + img.width;
    int neighborRight = centralPixel + img.channelNumber;
    int neighborTopRight = neighborRight - img.width;
    int neighborBottomRight = neighborRight + img.width;
    int neighborBottom = centralPixel + img.width;

    int neighbors[] = {
        neighborTopLeft, neighborTop, neighborTopRight,
        neighborLeft, centralPixel, neighborRight,
        neighborBottomLeft, neighborBottom, neighborBottomRight
        };
    int neighborLen = sizeof(neighbors) / sizeof(neighbors[0]);
    
    double neighborSum = 0;
    for (int i=0; i<neighborLen; i++) {
        if (neighbors[i] < 0 || neighbors[i] > img.size) continue;
        neighborSum += *(img.data+neighbors[i]);
    }
    return neighborSum;
}