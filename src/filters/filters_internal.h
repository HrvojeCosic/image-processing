#ifndef FILTERS_INTERNAL_H
#define FILTERS_INTERNAL_H

#include "../Image.h"

// Otsu's method
int computeThreshold(IMAGE);
int* getPixelHistogram(IMAGE);


// Sobel operator
int getHorizontalGradient(IMAGE, int, int, int[3][3]);
int getVerticalGradient(IMAGE, int, int, int[3][3]);

void quickSortPixels(uint8_t*, int, int, int);

#endif