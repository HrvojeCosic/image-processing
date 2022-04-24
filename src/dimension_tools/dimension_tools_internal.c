#include "dimension_tools.h"

void fixAspectRatio(IMAGE image, int* wProp, int* hProp) {
    float aspectRatio = (float)image.width / image.height;
    if (*wProp != 0) {
        *hProp = (*wProp) / aspectRatio;
    } else if (*hProp != 0) {
        *wProp = (*hProp) * aspectRatio;
    }
}

void transposeImage(IMAGE* originalImg, IMAGE* newImg) {
    for (int y=0; y<originalImg->height * originalImg->channelNumber; y+=originalImg->channelNumber) {
        for (int x=0; x<originalImg->width * originalImg->channelNumber; x+=originalImg->channelNumber) {
            int ch = originalImg->channelNumber;
            while (ch != 0) {
                newImg->data[x*originalImg->height + y + ch] = originalImg->data[y*originalImg->width + x + ch];
                ch--;
            }
        }
    }
}