#include "dimension_tools.h"
#include "dimension_tools.h"

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

    writeToImg("./processedImg.jpg", img);
    printf("Image has been flipped horizontally.\n");
    free(img.data);
}