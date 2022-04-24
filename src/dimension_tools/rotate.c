#include "dimension_tools.h"

void rotateLeft(char* filename) {
    IMAGE originalImg = readImg(filename);
    IMAGE newImg = readImg(filename);

    newImg.width = originalImg.height;
    newImg.height = originalImg.width;

    for (int y=0; y<originalImg.height * originalImg.channelNumber; y+=originalImg.channelNumber) {
        for (int x=0; x<originalImg.width * originalImg.channelNumber; x+=originalImg.channelNumber) {
            int ch = originalImg.channelNumber;
            while (ch != 0) {
                newImg.data[x*originalImg.height + y + ch] = originalImg.data[y*originalImg.width + x + ch];
                ch--;
            }
        }
    }

    submitChanges(newImg);
    printf("Image rotated 90 degrees to the left successfuly.\n");
    free(newImg.data);
    free(originalImg.data);
}

void rotateRight(char* filename) {
    IMAGE originalImg = readImg(filename);
    IMAGE newImg = readImg(filename);

    newImg.width = originalImg.height;
    newImg.height = originalImg.width;

    for (int y=0; y<originalImg.height * originalImg.channelNumber; y+=originalImg.channelNumber) {
        for (int x=0; x<originalImg.width * originalImg.channelNumber; x+=originalImg.channelNumber) {
            int ch = originalImg.channelNumber;
            while (ch != 0) {
                newImg.data[x*originalImg.height + y + ch] = originalImg.data[y*originalImg.width + x + ch];
                ch--;
            }
        }
    }

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
    printf("Image rotated 90 degrees to the right successfuly.\n");
    free(newImg.data);
    free(originalImg.data);
}