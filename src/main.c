#include "Image.c"

int main() {
    IMAGE img = readImg("exampleImg.jpg");
    free(img.data);
    return 0;
}
