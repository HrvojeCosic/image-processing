#include "Image.h"
#include "./dimension_tools/dimension_tools.h"
#include "./filters/filters.h"

int main() {
    applyBoxBlur("exampleImg.jpg");
    return 0;
}
