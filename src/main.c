#include "Image.h"
#include "./resize/nearestNeighbor.h"
#include "./filters/filters.h"

int main() {
    applyGrayscale("exampleImg.jpg");
    return 0;
}
