#include "filters.h"
#include "filters_internal.h"
#include <stdio.h>
#include <stdlib.h>

IMAGE img;
void applyBoxBlur(char* filename, int intensity) {
    img = readImg(filename);
    if (intensity >= (img.channelNumber * 2)) {
        printf("Error: blur intensity too high. Choose a lower value.\n");
        return;
    }

    IMAGE newImg = readImg(filename);

    for (int y=0; y<img.height * img.channelNumber; y++) {
        for (int x=0; x<img.width; x++) {
            int neighborsSum = 0;

            int offset = img.channelNumber * intensity;
            neighborsSum += *(img.data + (img.width * y) + x);
            neighborsSum += *(img.data + (img.width * y) + x + offset);
            neighborsSum += *(img.data + (img.width * y) + x - offset);
            neighborsSum += *(img.data + (img.width * y + offset) + x);
            neighborsSum += *(img.data + (img.width * y - offset) + x);
            neighborsSum += *(img.data + (img.width * y + offset) + x - offset);
            neighborsSum += *(img.data + (img.width * y - offset) + x + offset);
            neighborsSum += *(img.data + (img.width * y - offset) + x - offset);
            neighborsSum += *(img.data + (img.width * y + offset) + x + offset);

            newImg.data[y*img.width + x] = neighborsSum / 9;
        }
    }

    submitChanges(newImg);
    printf("Image blurred (using box blur) successfully.\n");
    free(newImg.data);
    free(img.data);
    return;
}