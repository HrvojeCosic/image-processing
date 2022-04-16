#include "filters.h"

void applyGrayscale(char* filename) {
    IMAGE img = readImg(filename);

    if (img.channelNumber < 3) {
        printf("Given image is already grayscale.\n");
        return;
    }

    for (int i=0; i<img.size; i+=img.channelNumber) {
        int greyLvl = (img.data[i] + img.data[i + 1] + img.data[i + 2]) / 3;

        for (int j=i; j < i+img.channelNumber; j++)
            *(img.data+j) = greyLvl;
    }

    writeToImg("./processedImg.jpg", img);
    printf("Grayscale applied successfuly.\n");
    free(img.data);
}
