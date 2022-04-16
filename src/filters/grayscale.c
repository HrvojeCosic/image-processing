#include "filters.h"

void applyGrayscale(char* filename) {
    IMAGE img = readImg(filename);

    if (img.channelNumber < 3) {
        printf("Given image is already grayscale.\n");
        return;
    }

    for (int i=0; i<img.size; i+=img.channelNumber) {
        int ch = img.channelNumber;
        int grayLvl = 0;
        while(ch != 0) grayLvl += *(img.data + i + (--ch));
        grayLvl /= img.channelNumber;

        ch = img.channelNumber;
        while(ch != 0) *(img.data + i + (--ch)) = grayLvl;

    }

    writeToImg("./processedImg.jpg", img);
    printf("Grayscale applied successfuly.\n");
    free(img.data);
}
