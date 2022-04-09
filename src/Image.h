#include <stdint.h>
#include <stdbool.h>

char* imageExtensions[] = {".jpg", ".png", ".bmp", NULL};
typedef struct Image {
    uint8_t* data;
    size_t size;
    int width;
    int height;
    int channelNumber;
}IMAGE;

char* getImgType(const char*);
IMAGE readImg(const char*);
bool writeToImg(char*);
char* createImgPath(char*, int, const char*);