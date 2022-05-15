#include "dimension_tools.h"
#include "dimension_tools.h"

#include "../Image.h"
#include <stdio.h>
#include <stdlib.h>

void flipHorizontal(char* filename) {
    IMAGE img = readImg(filename);

    unsigned left = 0;
    unsigned right = img.width;
    for (int y=0; y<img.height; y++) {
        while (left < right) {
            int px1Idx = (y * img.width + left) * img.channelNumber;
            int px2Idx = (y * img.width + right) * img.channelNumber;
            
            int ch = 0;
            while (ch != img.channelNumber) {
                uint8_t temp = img.data[px1Idx + ch];
                img.data[px1Idx + ch] = img.data[px2Idx + ch];
                img.data[px2Idx + ch] = temp;
                ch++;
            }
            left++;
            right--;            
        }
        left = 0;
        right = img.width;
    }

    submitChanges(img);
    printf("Image has been flipped horizontally.\n");
    free(img.data);
}

void flipVertical(char* filename) { 
    IMAGE img = readImg(filename);

    unsigned top = 0;
    unsigned chWidth = img.width * img.channelNumber;
    unsigned bottom = (img.height - 1) * chWidth;
    while (top < bottom) {

        for (int x=0; x<chWidth; x++) {
            int px1Idx = top + x;
            int px2Idx = bottom + x;

            uint8_t temp = img.data[px1Idx];
            img.data[px1Idx] = img.data[px2Idx];
            img.data[px2Idx] = temp;
        }
        top += chWidth;
        bottom -= chWidth;
        
    }

    submitChanges(img);
    printf("Image has been flipped vertically.\n");
    free(img.data);
}