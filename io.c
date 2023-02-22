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