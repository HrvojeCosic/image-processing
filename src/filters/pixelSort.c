#include "filters.h"
#include "filters_internal.h"
#include <stdio.h>
#include <stdlib.h>

void horizontalPixelSort(char* filename) {
    IMAGE img = readImg(filename);

    quickSortPixels(img.data, 0, img.size, img.channelNumber);
    
    submitChanges(img);
    printf("Pixels sorted successfully.\n");
    free(img.data);
}

void quickSortPixels(uint8_t* arr, int l, int r, int chN) {
    if (l >= r) return;
    int i=l-chN, j=0, chTemp;
    for (j=l; j<r; j+=chN) 
    {
        float currChAvg=0, pivotChAvg=0;
        chTemp = chN;
        while (chTemp != 0) {
            chTemp--;
            currChAvg += arr[j+chTemp];
            pivotChAvg += arr[r-chTemp];
        }
        currChAvg /= 3; pivotChAvg /= 3;

        if (currChAvg < pivotChAvg) {
            i+=chN;
            
            chTemp = chN;
            while (chTemp != 0) {
                chTemp--;
                int temp = arr[i+chTemp];
                arr[i+chTemp] = arr[j+chTemp];
                arr[j+chTemp] = temp;
            }
        }
    }
    int pIdx = i+chN;

    chTemp = chN;
    while (chTemp != 0) {
        chTemp--;
        int temp = arr[pIdx+chTemp];
        arr[pIdx+chTemp] = arr[r+chTemp];
        arr[r+chTemp] = temp;
    }
    
    quickSortPixels(arr, l, pIdx-chN, chN);
    quickSortPixels(arr, pIdx+chN, r, chN);
}