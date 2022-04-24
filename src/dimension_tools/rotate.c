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