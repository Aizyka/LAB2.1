#include <stdio.h>
#include "definitions.h"

int getint_mm(char* msg, int min, int max) {
    printf("%s",msg);
    int i;
    while(!scanf("%d", &i) || i < min || i > max) {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}

int getint_m(char* msg, int min) {
    printf("%s",msg);
    int i;
    while(!scanf("%d", &i) || i < min) {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}

int getint(char* msg) {
    printf("%s",msg);
    int i;
    while(!scanf("%d", &i)) {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}

float getfloat_mm(char* msg, float min, float max) {
    printf("%s",msg);
    float i;
    while(!scanf("%f", &i) || i < min || i > max) {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}

float getfloat_m(char* msg, float min) {
    printf("%s",msg);
    float i;
    while(!scanf("%f", &i) || i < min) {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}

float getfloat(char* msg) {
    printf("%s",msg);
    float i;
    while(!scanf("%f", &i)) {
        printf("Invalid value!\n");
        rewind(stdin);
        printf("%s", msg);
    }
    return i;
}