#include "nearestNeighbor.h"

void resize(char* filename, IMAGE props) {
    IMAGE originalImg = readImg(filename);
    fixAspectRatio(originalImg, &props.width, &props.height);
}

void fixAspectRatio(IMAGE image, int* wProp, int* hProp) {
    float aspectRatio = (float)image.width / image.height;
    if (*wProp != 0) {
        *hProp = (*wProp)/aspectRatio;
    } else if (*hProp != 0) {
        *wProp = (*hProp)*aspectRatio;
    }
}