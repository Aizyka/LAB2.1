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
    int size = getint_m("Enter size: ", 1);
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
        price = getfloat_m("Price: ", 0);
        controlType = getint_mm("Control Type(1-Electric Sensor,2-Electric Button,3-Mechanic): ", 1, 3);
        compressorCount = getint_m("Compressor Count: ", 1);
        energyClass = getint_mm("Energy Class(1-A++,2-A+,3-A,4-E): ", 1, 4);
        capacity = getfloat_m("Capacity: ", 0);
        noFrost = getint_mm("No Frost: ", 0, 1);
        height = getfloat_m("Height: ", 0);
        width = getfloat_m("Width: ", 0);
        cameraCount = getint_m("Camera count: ", 0);
        printf("Color: ");
        scanf("%24s", color);
        (*arr)[i] = init(name, price,controlType,compressorCount,energyClass,capacity,noFrost,height,width,cameraCount,color);
        printf("--------------END--------------\n");
    }
}