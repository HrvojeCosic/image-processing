#include "src/Image.h"
#include "src/dimension_tools/dimension_tools.h"
#include "src/filters/filters.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void runChoice(int, char*, int);
void runInputInitialFilename();
void runInputProcessedFilename();
void setProcessedImageFilenameIndex();

char newImageBool = 'N';
int choice;
char filename[40];
int counter = 0;


int main () {
    runInputInitialFilename();
    
    printf("*****************************\n");
    printf("1 - Apply binary filter\n");
    printf("2 - Apply grayscale filter\n");
    printf("3 - Blur\n");
    printf("4 - Accentuate edges\n");
    printf("5 - Flip\n");
    printf("6 - Rotate\n");
    printf("7 - Resize\n");
    printf("8 - Sort pixels\n");
    printf("9+ - Exit\n");
    printf("*****************************\n");

    for (;;) {
        printf("\nInput the process number: ");
        scanf("%d", &choice);
        getchar();

        if (choice >= 9) { // todo: fix hardcoded number
            printf("Exiting...");
            exit(0);
         }

        if (counter > 0) {
            printf("\nChoose new image to be processed? (Y/N): ");
            scanf("%c", &newImageBool);
            getchar();
            toupper(newImageBool) == 'Y' ? runInputInitialFilename() : runInputProcessedFilename();
        }

        runChoice(choice, filename, counter);
        counter++;
    }
}

void runInputInitialFilename () {
    printf("Input the image file name (name.extension): ");
    scanf("%s", filename); 
    getchar();

    getImgType(filename);
    readImg(filename);

    setProcessedImageFilenameIndex();
}

void setProcessedImageFilenameIndex () {
    char counterStringified[10] = {0};
    sprintf(counterStringified, "%d", counter);
    sprintf(processedImgFilename, "%s%s%s",
    "processedImg", counterStringified, getImgType(filename)
    );
    rename("processedImg.jpg", processedImgFilename );
}

void runInputProcessedFilename () {
    printf("\nCreate separate image for applied effects? (Y/N): ");
    scanf("%c", &newImageBool);
    getchar();
    if (toupper(newImageBool) == 'Y') {
        setProcessedImageFilenameIndex();
    }
}

void runChoice(int choice, char* initialFilename, int counter) {
        char filename[40] = {0};
        if (counter > 0 && toupper(newImageBool) != 'Y') {
            strcat(filename, processedImgFilename);
        } else {
            strcpy(filename, initialFilename);
        }

        int blurRadius;
        char direction;
        IMAGE newProps = { NULL, 0, 0, 0, 3 };
    
        switch (choice) {
        case 1:
            applyBinary(filename);
            break;
        case 2: 
            applyGrayscale(filename);
            break;
        case 3:
            printf("Input blur radius: ");
            scanf("%d", &blurRadius);
            applyBoxBlur(filename, blurRadius);
            break;
        case 4:
            accentuateEdges(filename);
            break;
        case 5:
            printf("vertically or horizontally? (type v/h): ");
            direction = getchar();
            direction == 'v' ? flipVertical(filename) 
            : direction == 'h' ? flipHorizontal(filename) 
            : printf("Invalid choice.\n");
            break;
        case 6:
            printf("to the left or right? (type l/r): ");
            direction = getchar();
            direction == 'l' ? rotateLeft(filename) 
            : direction == 'r' ? rotateRight(filename) 
            : printf("Invalid choice.\n");
            break;
        case 7:
            printf("Input new width: "); scanf("%d", &newProps.width);
            printf("Input new height: "); scanf("%d", &newProps.height);
            nearestNeighborResize(filename, newProps);
            break;
        case 8:
            horizontalPixelSort(filename);
            break;
        default:
            printf("Exiting...");
            exit(0);
    }
}
