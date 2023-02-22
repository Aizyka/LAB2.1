#include "definitions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int compareName(const Refrigerator* a, const Refrigerator* b) {
    return strcmp(a->name, b->name);
}
int comparePrice(const Refrigerator * a, const Refrigerator * b) {
    if(a->price<b->price)
        return -1;
    else if(a->price>b->price)
        return 1;
    return 0;
}
int compareControlType(const Refrigerator * a, const Refrigerator * b) {
    if(a->controlType<b->controlType)
        return -1;
    else if(a->controlType>b->controlType)
        return 1;
    return 0;
}
int compareCompressorsCount(const Refrigerator * a, const Refrigerator * b) {
    if(a->compressorCount<b->compressorCount)
        return -1;
    else if(a->compressorCount>b->compressorCount)
        return 1;
    return 0;
}
int compareEnergyClass(const Refrigerator * a, const Refrigerator * b) {
    if(a->energyClass<b->energyClass)
        return -1;
    else if(a->energyClass>b->energyClass)
        return 1;
    return 0;
}
int compareCapacity(const Refrigerator * a, const Refrigerator * b) {
    if(a->capacity<b->capacity)
        return -1;
    else if(a->capacity>b->capacity)
        return 1;
    return 0;
}
int compareNoFrost(const Refrigerator * a, const Refrigerator * b) {
    if(a->noFrost<b->noFrost)
        return -1;
    else if(a->noFrost>b->noFrost)
        return 1;
    return 0;
}
int compareHeight(const Refrigerator * a, Refrigerator * b) {
    if(a->height<b->height)
        return -1;
    else if(a->height>b->height)
        return 1;
    return 0;
}
int compareWidth(const Refrigerator * a, Refrigerator * b) {
    if(a->width<b->width)
        return -1;
    else if(a->width>b->width)
        return 1;
    return 0;
}
int compareCamerasCount(const Refrigerator * a, Refrigerator * b) {
    if(a->cameraCount<b->cameraCount)
        return -1;
    else if(a->cameraCount>b->cameraCount)
        return 1;
    return 0;
}
int compareColor(const Refrigerator* a, Refrigerator* b) {
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
    int (*compareTypes[11]) (Refrigerator*, Refrigerator*) = {&compareName, &comparePrice, &compareControlType,
                                                              &compareCompressorsCount, &compareEnergyClass, &compareCapacity,
                                                              &compareNoFrost, &compareHeight, &compareWidth,
                                                              &compareCamerasCount, &compareColor};
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