#include "resize_internal.h"

void fixAspectRatio(IMAGE image, int* wProp, int* hProp) {
    float aspectRatio = (float)image.width / image.height;
    if (*wProp != 0) {
        *hProp = (*wProp) / aspectRatio;
    } else if (*hProp != 0) {
        *wProp = (*hProp) * aspectRatio;
    }
}