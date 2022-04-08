#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb/stb_image_write.h"
#include "Image.h"
#include <string.h>

IMAGE readImg(const char* filename) {
    char path[4] = "../";

    IMAGE img = {0};
    img.data = stbi_load(
        strcat(path, filename), &img.width, &img.height, &img.channelNumber, 0
    );
    img.size = img.width*img.height*img.channelNumber;

    if (img.data == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    return img;
}
