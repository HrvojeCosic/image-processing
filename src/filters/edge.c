#include "filters.h"

void accentuateEdges (char* filename) {
    IMAGE img = readImg(filename);

    if (img.channelNumber >= 3) {
        applyGrayscale(filename);
        img = readImg("./processedImg.jpg");
    }

    int kernelX[3][3] = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}
    };
    int kernelY[3][3] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    };
}