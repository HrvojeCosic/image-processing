#include "filters.h"
#include "filters_internal.h"
#include <stdio.h>
#include <stdlib.h>

void horizontalPixelSort(char* filename) {
    IMAGE img = readImg(filename);

    for (int i=0; i<img.channelNumber; i++) {
            
        for (int j=i; j<img.size; j++) {
            for (int k=j; k<img.size; k+=img.channelNumber) {
                if (*(img.data+j) > *(img.data+k)) {
                    uint8_t temp = *(img.data+j);
                    *(img.data+j) = *(img.data+k);
                    *(img.data+k) = temp;
                }
            }    
        }
            
    }

    submitChanges(img);
    printf("Pixels sorted successfully.\n");
    free(img.data);
}
