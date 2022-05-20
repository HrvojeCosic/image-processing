#include "filters_internal.h"
#include <math.h>

int computeThreshold(IMAGE img) {
    int* histogram = getPixelHistogram(img);
    int threshold = 0;
    const int maxPixelIntensity = 255; 
    float globalPixelOccurance=0, c1PixelOccurance=0, c2PixelOccurance=0, c1ProbSum=0, c2ProbSum=0, varMax=0;

    for (int i=0; i<=maxPixelIntensity; i++)
        globalPixelOccurance += (i * histogram[i]);

    for (int i=0 ; i<=maxPixelIntensity; i++) {
        c1ProbSum += histogram[i];
        c2ProbSum = (img.width * img.height) - c1ProbSum;
    
        if (c1ProbSum == 0 || c2ProbSum == 0) continue;

        c1PixelOccurance += i * histogram[i];
        c2PixelOccurance = globalPixelOccurance - c1PixelOccurance; 
        float c1Mean = c1PixelOccurance / c1ProbSum;
        float c2Mean = c2PixelOccurance / c2ProbSum;

        float betweenClassVariance = c1ProbSum * c2ProbSum * pow((c1Mean - c2Mean), 2);
        if (betweenClassVariance > varMax) {
            threshold = i;
            varMax = betweenClassVariance;
        }
    }
    return threshold;
}

int* getPixelHistogram (IMAGE img) {
    static int histogram[256];
    const int maxPixelIntensity = 255;
    for (int i=0; i<=maxPixelIntensity; i++)
        histogram[i] = 0;

    for (int i=0; i<img.size; i+=img.channelNumber) {
        int channelAvg = 0;
        int ch = img.channelNumber;
        while(ch != 0) channelAvg += *(img.data + i + (--ch));
        channelAvg /= img.channelNumber;

        histogram[channelAvg]++;
    }

    return histogram;
}

int getHorizontalGradient (IMAGE img, int y, int x, int kernelX[3][3]) {
    int gradientX = 0;
    gradientX += img.data[ (img.width * y) + x + img.channelNumber ] * kernelX[1][2];
    gradientX += img.data[ (img.width * y) + x - img.channelNumber ] * kernelX[1][0];
    gradientX += img.data[ (img.width * y + img.channelNumber) + x - img.channelNumber ] * kernelX[2][0];
    gradientX += img.data[ (img.width * y - img.channelNumber) + x + img.channelNumber ] * kernelX[0][2];
    gradientX += img.data[ (img.width * y - img.channelNumber) + x - img.channelNumber ] * kernelX[0][0];
    gradientX += img.data[ (img.width * y + img.channelNumber) + x + img.channelNumber ] * kernelX[2][2];
    return gradientX;
}

int getVerticalGradient (IMAGE img, int y, int x, int kernelY[3][3]) {
    int gradientY = 0;
    gradientY += img.data[ (img.width * y + img.channelNumber) + x + img.channelNumber ] * kernelY[2][2];
    gradientY += img.data[ (img.width * y + img.channelNumber) + x - img.channelNumber ] * kernelY[2][0];
    gradientY += img.data[ (img.width * y - img.channelNumber) + x + img.channelNumber ] * kernelY[0][2];
    gradientY += img.data[ (img.width * y - img.channelNumber) + x - img.channelNumber ] * kernelY[0][0];
    gradientY += img.data[ (img.width * y - img.channelNumber) + x ] * kernelY[0][1];
    gradientY += img.data[ (img.width * y + img.channelNumber) + x ] * kernelY[2][1];

    return gradientY;
}

void quickSortPixels(uint8_t* arr, int l, int r, int chN) {
    if (l >= r) return;
    int i=l-chN, j=0, chTemp;
    for (j=l; j<r; j+=chN) {
        float currChAvg=0, pivotChAvg=0;
        chTemp = chN;
        while (chTemp != 0) {
            chTemp--;
            currChAvg += arr[j+chTemp];
            pivotChAvg += arr[r-chTemp];
        }
        currChAvg /= chN; pivotChAvg /= chN;

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