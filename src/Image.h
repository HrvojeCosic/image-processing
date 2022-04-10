#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Image.h"
#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"


typedef struct Image {
    uint8_t* data;
    size_t size;
    int width;
    int height;
    int channelNumber;
}IMAGE;

char* getImgType(const char*);
IMAGE readImg(const char*);
bool writeToImg(char*, IMAGE);
void createImgPath(char*, int, const char*);

#endif