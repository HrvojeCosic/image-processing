#include "filters_internal.h"

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
    gradientX += img.data[ (img.width * y) + x + 1 ] * kernelX[1][2];
    gradientX += img.data[ (img.width * y) + x - 1 ] * kernelX[1][0];
    gradientX += img.data[ (img.width * y + 1) + x - 1 ] * kernelX[2][0];
    gradientX += img.data[ (img.width * y - 1) + x + 1 ] * kernelX[0][2];
    gradientX += img.data[ (img.width * y - 1) + x - 1 ] * kernelX[0][0];
    gradientX += img.data[ (img.width * y + 1) + x + 1 ] * kernelX[2][2];

    return gradientX;
}