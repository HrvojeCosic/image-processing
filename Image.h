#include <stdint.h>
#include <stdbool.h>

typedef struct Image {
    uint8_t* data;
    size_t size;
    int width;
    int height;
    int channelNumber; // number of colors values per pixel (e.g. RGB has 3)
}IMAGE;

bool readImg(const char* filename);
bool writeToImg(char* filename);