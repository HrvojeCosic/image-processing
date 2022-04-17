#include "dimension_tools.h"
#include "dimension_tools_internal.h"

void nearestNeighborResize(char* filename, IMAGE newProps) {
    IMAGE originalImg = readImg(filename);
    fixAspectRatio(originalImg, &newProps.width, &newProps.height);

    newProps.size = newProps.width * newProps.height * originalImg.channelNumber;
    if (newProps.size <= 0) {
        printf("Target image properties are invalid\n");
        exit(1);    
    }
    newProps.data = malloc(newProps.size * sizeof(uint8_t));

    double xRatio = originalImg.width / (double)newProps.width;
    double yRatio = originalImg.height / (double)newProps.height;
    int ch = originalImg.channelNumber;
    for (int y=0; y<newProps.height; y++) {
        for (int x=0; x<newProps.width; x++) {
            int newPos = (x + y * newProps.width) * ch;
            int orgPos = ( floor(x * xRatio) + (originalImg.width * floor(y * yRatio)) ) * ch;
            for (int i=0; i<ch; i++) 
                newProps.data[newPos + i] = originalImg.data[orgPos + i];
        }
    }

    writeToImg("./processedImg.jpg", newProps);

    printf("Image resized successfuly.\n");
    free(newProps.data);
    free(originalImg.data);
}
