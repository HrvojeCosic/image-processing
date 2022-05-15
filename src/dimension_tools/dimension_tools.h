#ifndef DIMENSION_TOOLS_H
#define DIMENSION_TOOLS_H

#include "../Image.h"

void nearestNeighborResize(char*, IMAGE);
void flipHorizontal(char*);
void flipVertical(char*);
void rotateLeft(char*);
void rotateRight(char*);

#endif