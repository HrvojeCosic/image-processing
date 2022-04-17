#ifndef FILTERS_INTERNAL_H
#define FILTERS_INTERNAL_H

#include "../Image.h"
#include <math.h>

int computeThreshold(IMAGE); // https://en.wikipedia.org/wiki/Otsu%27s_method
int* getPixelHistogram(IMAGE);

#endif