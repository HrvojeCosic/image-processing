#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

#include <math.h>
#include "../Image.h"

void nearestNeighborResize(char*, IMAGE);
void fixAspectRatio(IMAGE, int*, int*);

#endif