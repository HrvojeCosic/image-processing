#include "filters.h"

void applyBinary(char* filename) {
    IMAGE img = readImg(filename);

    if (img.channelNumber >= 3) {
        applyGrayscale(filename);
        img = readImg("./exampleImg.jpg");
    }

    for (int i=0; i<img.size; i+=img.channelNumber) {
        int greyLvl = *(img.data+i);
        int finalPixel = (greyLvl >= 0 && greyLvl < 50) ? 0 : 255;

        for (int j=i; j < i+img.channelNumber; j++)
            *(img.data+j) = finalPixel;
    }

    writeToImg("./processedImg.jpg", img);
    printf("Binary filter applied successfuly.\n");
    free(img.data);
}