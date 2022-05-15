#include "dimension_tools.h"
#include "dimension_tools_internal.h"
#include <stdio.h>
#include <stdlib.h>

void rotateLeft(char* filename) {
    IMAGE originalImg = readImg(filename);
    IMAGE newImg = readImg(filename);

    newImg.width = originalImg.height;
    newImg.height = originalImg.width;

    transposeImage(&originalImg, &newImg);

    submitChanges(newImg);
    printf("Image rotated 90 degrees to the left successfully.\n");
    free(newImg.data);
    free(originalImg.data);
}

void rotateRight(char* filename) {
    IMAGE originalImg = readImg(filename);
    IMAGE newImg = readImg(filename);

    newImg.width = originalImg.height;
    newImg.height = originalImg.width;

    transposeImage(&originalImg, &newImg);

    for (int y=0; y<newImg.height*newImg.channelNumber; y+=newImg.channelNumber) {
        int leftIdx = newImg.channelNumber - 1;
        int rightIdx = newImg.width * newImg.channelNumber - 1;

        while (leftIdx < rightIdx) {

            int ch = newImg.channelNumber;
            uint8_t temp;
            while (ch != 0) {
                ch--;
                temp = newImg.data[y*newImg.width + leftIdx - ch];
                newImg.data[y*newImg.width + leftIdx - ch] = newImg.data[y*newImg.width + rightIdx - ch];
                newImg.data[y*newImg.width + rightIdx - ch] = temp;
            }

            leftIdx += newImg.channelNumber;
            rightIdx -= newImg.channelNumber;
        }
    }

    submitChanges(newImg);
    printf("Image rotated 90 degrees to the right successfully.\n");
    free(newImg.data);
    free(originalImg.data);
}