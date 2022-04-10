#include "Image.h"
#include "./resize/nearestNeighbor.h"

int main() {
    IMAGE resizeProps = { NULL, 0, 200, 0, 3 };
    resize("exampleImg.jpg", resizeProps);
    return 0;
}
