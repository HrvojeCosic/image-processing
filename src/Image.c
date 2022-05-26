#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Image.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../lib/stb/stb_image.h"
#include "../lib/stb/stb_image_write.h"

char* imageExtensions[] = {".jpg", ".png", ".bmp", NULL};

IMAGE readImg(const char* filename) {
    char path[70] = "";
    createImgPath(path, sizeof(path), filename);

    IMAGE img = {0};

	FILE* file = fopen(path, "rb");
  	if(file) {
  		fclose(file);
    } else {
        printf("Error: that image can not be loaded.\n");
        exit(1);
    }

    img.data = stbi_load(path, &img.width, &img.height, &img.channelNumber, 0);
    img.size = img.width*img.height*img.channelNumber;

    return img;
}

bool writeToImg(char* filename, IMAGE props) {
    char* type = getImgType(filename);
    char fullFilename[70] = "";
    createImgPath(fullFilename, sizeof(fullFilename), filename);
    
    int success = 0;
    if (strcmp(type, ".jpg") == 0) {
        success = stbi_write_jpg(
            fullFilename, props.width, props.height, 
            props.channelNumber, props.data, 100
            );
    } else if (strcmp(type, ".png")) {
        int stride = props.width*props.channelNumber;
        success = stbi_write_png(
            fullFilename, props.width, props.height, 
            props.channelNumber, props.data, stride
            );
    } else if (strcmp(type, ".bmp")) {
        success = stbi_write_bmp(
            fullFilename, props.width, props.height, 
            props.channelNumber, props.data
            );
    }

    return success != 0;
}

void submitChanges(IMAGE img) {
    char currentProcessedImgPath[100];
    sprintf(currentProcessedImgPath, "./%s", processedImgFilename);
    writeToImg(currentProcessedImgPath, img);
}

void createImgPath(char* dest, int destSize, const char* filename) {
    char dirMovement[4] = ""; // TODO: allow saving in other folders
    int moved = strcat_s(dest, destSize, dirMovement);
    int applied = strcat_s(dest, destSize, filename);
    if (moved != 0 || applied != 0) {
        printf("Error in creating the image path\n");
        exit(1);
    }
}

char* getImgType(const char* filename) {
    const char* fileExt = strrchr(filename, '.');
    
    if (fileExt == NULL) {
        printf("Error: File extension not inputted");
        exit(1);
    }

    int i = 0;
    while (*(imageExtensions+i) != NULL) {
        if (strcmp(fileExt, *(imageExtensions+i)) == 0) {
            return *(imageExtensions+i);
        }
        i++;
    }

    printf("Error: image type not supported.\n");
    exit(1);
}