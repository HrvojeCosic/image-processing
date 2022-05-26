#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

char processedImgFilename[100];

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
void submitChanges(IMAGE);

#endif