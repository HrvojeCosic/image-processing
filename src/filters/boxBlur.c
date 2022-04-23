#include "filters.h"
#include "filters_internal.h"

IMAGE img;
void applyBoxBlur(char* filename) {
    img = readImg(filename);
    IMAGE newImg = readImg(filename);

    for (int y=0; y<img.height * img.channelNumber; y++) {
        for (int x=0; x<img.width; x++) {
            int neighborsSum = 0;
            neighborsSum += *(img.data + (img.width * y) + x);
            neighborsSum += *(img.data + (img.width * y) + x + img.channelNumber);
            neighborsSum += *(img.data + (img.width * y) + x - img.channelNumber);
            neighborsSum += *(img.data + (img.width * y + img.channelNumber) + x);
            neighborsSum += *(img.data + (img.width * y - img.channelNumber) + x);
            neighborsSum += *(img.data + (img.width * y - img.channelNumber) + x + img.channelNumber);
            neighborsSum += *(img.data + (img.width * y + img.channelNumber) + x - img.channelNumber);
            neighborsSum += *(img.data + (img.width * y - img.channelNumber) + x - img.channelNumber);
            neighborsSum += *(img.data + (img.width * y + img.channelNumber) + x + img.channelNumber);

            newImg.data[y*img.width + x] = neighborsSum / 9;
        }
    }

    submitChanges(newImg);
    printf("Image blurred (using box blur) successfully.\n");
    free(newImg.data);
    free(img.data);
    return;
}