#ifndef LAB2_1_DEFINITIONS_H
#define LAB2_1_DEFINITIONS_H
#include "struct.h"
Refrigerator init(char name[100], float price, int controlType, int compressorCount, int energyClass, float capacity, int noFrost, float height, float width, int cameraCount, char color[25]);
Refrigerator * createArray(int count);
void removeFromArray(Refrigerator **arr, int *size, int index);
void showArray(Refrigerator* array, int count);
void fillArray(Refrigerator** arr, int* sizeArr);
void htmlParse(Refrigerator** refrigerators, int* size);
void sort(Refrigerator * arr, int size);
int getint_mm(char* msg, int min, int max);
int getint_m(char* msg, int min);
int getint(char* msg);
float getfloat_mm(char* msg, float min, float max);
float getfloat_m(char* msg, float min);
float getfloat(char* msg);
#endif //LAB2_1_DEFINITIONS_H
