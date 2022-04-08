#include <stdint.h>
#include <stdbool.h>

typedef struct Image {
    uint8_t* data;
    size_t size;
    int width;
    int height;
    int channelNumber;
}IMAGE;

bool readImg(const char* filename);
bool writeToImg(char* filename);