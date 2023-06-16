#include "./include/dimension_tools.h"
#include "./include/filters.h"
#include "./include/Image.h"
#include <stb_image.h>
#include <stb_image_write.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    char filename[64];
    char* originalFilename = argv[1];
    char* processingValue = argv[3];
    char* processingOption = argv[2];
    strcpy(filename, originalFilename);

    sprintf(processedImgFilename, "%s%s",
            "processed-", filename);
    rename("processedImg.jpg", processedImgFilename );
    

    if (strcmp(processingOption, "binary")) {
        applyBinary(filename);
    } else if (strcmp(processingOption, "grayscale")) {
        applyGrayscale(filename);
    } else if (strcmp(processingOption, "blur")) {
        applyBoxBlur(filename, atoi(processingValue));
    } else if (strcmp(processingOption, "flip")) {
        if (strcmp(processingValue, "horizontal") == 0) {
            flipHorizontal(filename);
        } else if (strcmp(processingValue, "vertical") == 0) {
            flipVertical(filename);
        }
    } else if (strcmp(processingOption, "rotate")) {
        if (strcmp(processingValue, "left") == 0) {
            rotateLeft(filename);
        } else if (strcmp(processingValue, "right") == 0) {
           rotateRight(filename);
        }
    } else if (strcmp(processingOption, "pixel sort")) {
        horizontalPixelSort(filename);
    }

    return 0;
}
