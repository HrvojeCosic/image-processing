#include "nearestNeighbor.h"

void resize(char* filename, IMAGE props) {
    IMAGE img = readImg(filename);
    printf("test: %d\n", props.width);
    printf("test2: %d\n", img.width);
}