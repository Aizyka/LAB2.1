#include "definitions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int compareName(Refrigerator* a, Refrigerator* b) {
    return strcmp(a->name, b->name);
}
int comparePrice(Refrigerator * a, Refrigerator * b) {
    return (a->price<b->price) ? -1 : ((a->price>b->price) ? 1 : 0);
}
int compareControlType(Refrigerator * a, Refrigerator * b) {
    return (a->controlType<b->controlType) ? -1 : ((a->controlType>b->controlType) ? 1 : 0);
}
int compareCompressorsCount(Refrigerator * a, Refrigerator * b) {
    return (a->compressorCount<b->compressorCount) ? -1 : ((a->compressorCount>b->compressorCount) ? 1 : 0);
}
int compareEnergyClass(Refrigerator * a, Refrigerator * b) {
    return (a->energyClass<b->energyClass) ? -1 : ((a->energyClass>b->energyClass) ? 1 : 0);
}
int compareCapacity(Refrigerator * a, Refrigerator * b) {
    return (a->capacity<b->capacity) ? -1 : ((a->capacity>b->capacity) ? 1 : 0);
}
int compareNoFrost(Refrigerator * a, Refrigerator * b) {
    return (a->noFrost<b->noFrost) ? -1 : ((a->noFrost>b->noFrost) ? 1 : 0);
}
int compareHeight(Refrigerator * a, Refrigerator * b) {
    return (a->height<b->height) ? -1 : ((a->height>b->height) ? 1 : 0);
}
int compareWidth(Refrigerator * a, Refrigerator * b) {
    return (a->width<b->width) ? -1 : ((a->width>b->width) ? 1 : 0);
}
int compareCamerasCount(Refrigerator * a, Refrigerator * b) {
    return (a->cameraCount<b->cameraCount) ? -1 : ((a->cameraCount>b->cameraCount) ? 1 : 0);
}
int compareColor(Refrigerator* a, Refrigerator* b) {
    return strcmp(a->color, b->color);
}

int secondSort(int (*compareTypes[11]) (Refrigerator*, Refrigerator*), Refrigerator* a, Refrigerator* b) {
    int comp = 0;
    for(int i = 0; i < 11 && comp == 0; i++) {
        if(compareTypes[i] == NULL) break;
        comp = ((*compareTypes[i])(a, b));
    }
    return comp;
}

void sort(Refrigerator * arr, int size) {
    int (*compareTypes[11]) (Refrigerator*, Refrigerator*) = {compareName, comparePrice, compareControlType,
                                                              compareCompressorsCount, compareEnergyClass, compareCapacity,
                                                              compareNoFrost, compareHeight, compareWidth,
                                                              compareCamerasCount, compareColor};
    int count;
    printf("Choose sort count: ");
    while(!scanf("%d", &count) || count < 1 || count > 11) {
        printf("Invalid sort count!\n");
        rewind(stdin);
        printf("Choose sort count: ");
    }
    int (*secondTypes[11]) (Refrigerator*, Refrigerator*);
    for(int i = 0; i < count; i++) {
        int ss;
        printf("Choose sort type: ");
        while(!scanf("%d", &ss) || ss < 0 || ss > 10) {
            printf("Invalid sort type!\n");
            rewind(stdin);
            printf("Choose second sort type: ");
        }
        secondTypes[i] = compareTypes[ss];
    }
    for(int i = count; i < 11; i++) {
        secondTypes[i] = NULL;
    }

    qsort_r(arr, size, sizeof(Refrigerator), secondTypes, secondSort);
}