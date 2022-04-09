#include <stdint.h>
#include <stdbool.h>

typedef struct Image {
    uint8_t* data;
    size_t size;
    int width;
    int height;
    int channelNumber;
}IMAGE;

IMAGE readImg(const char*);
bool writeToImg(char*);
char* createImagePath(char*, int, const char*);