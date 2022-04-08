#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb/stb_image_write.h"
#include "Image.h"
#include <string.h>

bool readImg(const char* filename) {
    char path[4] = "../";

    IMAGE img = {0};
    uint8_t *result = stbi_load(
        strcat(path, filename), &img.width, &img.height, &img.channelNumber, 0
    );
    if (result == NULL) {
        printf("Error in loading the image\n");
        return false;
    }
    return true;
}
