#ifndef FILTERS_INTERNAL_H
#define FILTERS_INTERNAL_H

#include "../Image.h"
#include <math.h>

int computeThreshold(IMAGE); // https://en.wikipedia.org/wiki/Otsu%27s_method
int* getPixelHistogram(IMAGE);

double getNeighborSum(int);

int getHorizontalGradient(IMAGE, int, int, int[3][3]);
int getVerticalGradient(IMAGE, int, int, int[3][3]);

#endif