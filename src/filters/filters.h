#ifndef FILTERS_H
#define FILTERS_H

#include "../Image.h"

void applyGrayscale(char*);
void applyBinary(char*);
void applyBoxBlur(char*, int);
void accentuateEdges(char*);
void horizontalPixelSort(char*);

#endif