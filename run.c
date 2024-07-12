#include "./include/dimension_tools.h"
#include "./include/filters.h"
#include "./include/Image.h"
#include <stb_image.h>
#include <stb_image_write.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    (void)argc;
    char filename[64];
    char* originalFilename = argv[1];
    char* processingValue = argv[3];
    char* processingOption = argv[2];
    strcpy(filename, originalFilename);

    sprintf(processedImgFilename, "%s%s",
            "processed-", filename);
    rename("processedImg.jpg", processedImgFilename );

    if (strcmp(processingOption, "binary") == 0) {
        applyBinary(filename);
    } else if (strcmp(processingOption, "grayscale") == 0) {
        applyGrayscale(filename);
    } else if (strcmp(processingOption, "blur") == 0) {
        applyBoxBlur(filename, atoi(processingValue));
    } else if (strcmp(processingOption, "flip") == 0) {
        if (strcmp(processingValue, "horizontal") == 0) {
            flipHorizontal(filename);
        } else if (strcmp(processingValue, "vertical") == 0) {
            flipVertical(filename);
        }
    } else if (strcmp(processingOption, "rotate") == 0) {
        if (strcmp(processingValue, "left") == 0) {
            rotateLeft(filename);
        } else if (strcmp(processingValue, "right") == 0) {
           rotateRight(filename);
        }
    } else if (strcmp(processingOption, "pixelSort") == 0) {
        horizontalPixelSort(filename);
    }

    return 0;
}
