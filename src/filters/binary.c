#include "filters.h"
#include "filters_internal.h"

void applyBinary(char* filename) {
    IMAGE img = readImg(filename);

    if (img.channelNumber >= 3) {
        applyGrayscale(filename);
        img = readImg("./processedImg.jpg");
    }

    int threshold = computeThreshold(img);

    for (int i=0; i<img.size; i+=img.channelNumber) {
        int greyLvl = *(img.data+i);
        int finalPixel = greyLvl < threshold ? 0 : 255;

        for (int j=i; j < i+img.channelNumber; j++)
            *(img.data+j) = finalPixel;
    }

    writeToImg("./processedImg.jpg", img);
    printf("Binary filter applied successfuly.\n");
    free(img.data);
}

int computeThreshold(IMAGE img) {
    int* histogram = getPixelHistogram(img);
    return 50; // TODO: naravno ne ovo
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
