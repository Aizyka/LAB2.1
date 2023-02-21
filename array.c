#include <stdlib.h>
#include <stdio.h>
#include "definitions.h"
const char *controlTypes[] = { "NONE", "Electric Sensor", "Electric Button", "Mechanic" };
const char *energyClasses[] = { "NONE", "A++", "A+", "A", "E" };
Refrigerator * createArray(int count) {
    return (Refrigerator *)calloc(count, sizeof(Refrigerator));
}

void removeFromArray(Refrigerator **arr, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index!\nValid index [0-%d]", *size);
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    *size -= 1;
    *arr = (Refrigerator*)realloc(*arr, (*size) * sizeof(Refrigerator));
}

void showArray(Refrigerator* array, int count) {
    for(int i = 0; i < count; i++) {
        printf("Struct %d\n", i);
        printf("Name: %s\n", array[i].name);
        printf("Price: %f\n", array[i].price);
        printf("Control Type: %s\n", controlTypes[array[i].controlType]);
        printf("Compressors Count: %i\n", array[i].compressorCount);
        printf("Energy Class: %s\n", energyClasses[array[i].energyClass]);
        printf("Capacity: %f\n", array[i].capacity);
        printf("No Frost: %i\n", array[i].noFrost);
        printf("Height: %f\n", array[i].height);
        printf("Width: %f\n", array[i].width);
        printf("Cameras Count: %i\n", array[i].cameraCount);
        printf("Color: %s\n", array[i].color);
        printf("--------------END--------------\n");
    }
}

void fillArray(Refrigerator** arr, int* sizeArr) {
    printf("Enter size: ");
    int size;
    while(!scanf("%d", &size) || size < 1) {
        printf("Invalid size!\n");
        rewind(stdin);
        printf("Enter size: ");
    }
    *arr = createArray(size);
    *sizeArr = size;

    for(int i = 0; i < size; i++) {
        char name[100];
        float price;
        int controlType;
        int compressorCount;
        int energyClass;
        float capacity;
        int noFrost;
        float height;
        float width;
        int cameraCount;
        char color[25];
        rewind(stdin);
        printf("Struct %d\n", i);
        printf("Name: ");
        scanf("%99s", name);
        printf("Price: ");
        while(!scanf("%f", &price) || price < 0) {
            printf("Invalid price!\n");
            rewind(stdin);
            printf("Price: ");
        }
        printf("Control Type(1-Electric Sensor,2-Electric Button,3-Mechanic): ");
        while(!scanf("%d", &controlType) || controlType < 1 || controlType > 3) {
            printf("Invalid control type!\n");
            rewind(stdin);
            printf("Control Type: ");
        }
        printf("Compressor Count: ");
        while(!scanf("%d", &compressorCount) || compressorCount < 1) {
            printf("Invalid price!\n");
            rewind(stdin);
            printf("Price: ");
        }
        printf("Energy Class(1-A++,2-A+,3-A,4-E): ");
        while(!scanf("%d", &energyClass) || controlType < 1 || controlType > 4) {
            printf("Invalid energy class!\n");
            rewind(stdin);
            printf("Energy Class: ");
        }
        printf("Capacity: ");
        while(!scanf("%f", &capacity) || capacity < 0) {
            printf("Invalid capacity!\n");
            rewind(stdin);
            printf("Capacity: ");
        }
        printf("No Frost: ");
        while(!scanf("%d", &noFrost) || noFrost < 0 || noFrost > 1) {
            printf("Invalid value!\n");
            rewind(stdin);
            printf("No Frost: ");
        }
        printf("Height: ");
        while(!scanf("%f", &height) || height < 0) {
            printf("Invalid height!\n");
            rewind(stdin);
            printf("Height: ");
        }
        printf("Width: ");
        while(!scanf("%f", &width) || width < 0) {
            printf("Invalid width!\n");
            rewind(stdin);
            printf("Width: ");
        }
        printf("Camera count: ");
        while(!scanf("%d", &cameraCount) || cameraCount < 0) {
            printf("Invalid value!\n");
            rewind(stdin);
            printf("Camera count: ");
        }
        printf("Color: ");
        scanf("%24s", color);
        (*arr)[i] = init(name, price,controlType,compressorCount,energyClass,capacity,noFrost,height,width,cameraCount,color);
        printf("--------------END--------------\n");
    }
}