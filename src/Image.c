#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb/stb_image_write.h"
#include "Image.h"
#include <string.h>

IMAGE readImg(const char* filename) {
    char path[70] = "";
    createImagePath(path, sizeof(path), filename);

    IMAGE img = {0};
    img.data = stbi_load(path, &img.width, &img.height, &img.channelNumber, 0);
    img.size = img.width*img.height*img.channelNumber;

    if (img.data == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    return img;
}

// bool writeToImage(char* filename) {
// }

char* createImagePath(char* dest, int destSize, const char* filename) {
    char dirMovement[4] = "../";
    int moved = strcat_s(dest, destSize, dirMovement);
    int applied = strcat_s(dest, destSize, filename);
    if (moved != 0 || applied != 0) {
        printf("Error in creating the image path\n");
        exit(1);
    }
}