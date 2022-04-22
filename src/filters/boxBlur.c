#include "filters.h"
#include "filters_internal.h"

IMAGE img;

void applyBoxBlur(char* filename) {
    img = readImg(filename);
    IMAGE imgCopy = img;  //TODO: DEEP COPY

    for (int y=1; y<img.height; y++) {
        for (int x=0; x<img.width*img.channelNumber; x+=img.channelNumber) {
            int newPixelValue = (int)getNeighborSum((y * img.width) + x);
            imgCopy.data[y*img.width + x] = newPixelValue;
        }
    }

    submitChanges(imgCopy);
    printf("Image blurred (using box blur) successfully.\n");
    free(imgCopy.data);
    free(img.data);
    return;
}

double getNeighborSum(int centralPixel) {
    // ALL THESE ARE STARTING(!) POSITIONS OF CORRESPONDING PIXELS
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

        int ch = img.channelNumber;
        double pixelAvg = 0; 
        while (ch != 0) pixelAvg += *(img.data+neighbors[i] + (--ch));
        pixelAvg /= img.channelNumber;

        neighborSum += pixelAvg;
    }

    return (neighborSum / 9);
}