#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "definitions.h"

char *findString(char *str, const char *substr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j])
                return &str[i];
        }
    }

    return NULL;
}

int getCount(const char *str, const char *substr) {
    int j; int count = 0;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j]) {
                count++;
            }
        }
    }

    return count;
}

int contains(const char *str, const char *substr) {
    int j;

    for(int i = 0; str[i]; i++) {
        if(str[i] == substr[0]) {
            for(j = 0; substr[j] && str[i+j] == substr[j]; j++);
            if(!substr[j]) {
                return 1;
            }
        }
    }

    return 0;
}

void getTagText(char *tag, char *buffer) {
    char *ptr1; const char *ptr2;

    ptr1 = findString(tag, ">") + 1;
    ptr2 = findString(ptr1, "<");
    strncpy(buffer, ptr1, ptr2-ptr1);
    buffer[ptr2-ptr1] = '\0';
}

char* getLeft(const char* str) {
    int sub = 0;
    char nbsp[6] = "&nbsp;";
    int j; int i;
    for(i = 0; str[i]; i++) {
        if(str[i] == '&' || str[i] == ' ') {
            for(j = 0; j < 6 && str[i+j] != nbsp[j]; j++);
            if(j == 6 || str[i] == ' ')
            {
                sub = i;
                break;
            }
        }
    }
    if(sub == 0)
        sub = i;
    char* buf = (char*)malloc((sub+1)*sizeof(char));
    strncpy(buf, str, sub);
    buf[sub] = '\0';
    return buf;
}
void removeSpaces(char *str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void parseContent(char* ptr, const char* localEnd, Refrigerator** refrigerators, int currPos) {
    char name[100]; float price = 0.0f; int controlType = 0; int compressorCount = 0; int energyClass = 0; float capacity = 0.0f; int noFrost = 0; float height = 0.0f; float width = 0.0f; int cameraCount = 0; char color[25];
    char buffer[1000]; char typeBuffer[1000];
    ptr = findString(ptr, "<span class=\"result__name\">");
    getTagText(ptr, buffer);
    snprintf(name, sizeof(name), "%s", buffer);
    char *descPtr = findString(ptr, "<td class='result__attr_var");
    while(descPtr != NULL && descPtr < localEnd) {
        getTagText(descPtr, typeBuffer);

        descPtr = findString(descPtr, "<td class='result__attr_val");
        getTagText(descPtr, buffer);

        if(contains(typeBuffer, "?????? ????????????????????")) {
            if(contains(buffer, "????????????????????????")) {
                controlType = Mechanic;
            }
            else if(contains(buffer, "?????????????????????? ??????????????????")) {
                controlType = ElectricButton;
            }
            else if(contains(buffer, "?????????????????????? ??????????????????")) {
                controlType = ElectricSensor;
            }
        }
        else if(contains(typeBuffer, "???????????????????? ????????????????????????")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%d", &compressorCount);
            free(gl);
        }
        else if(contains(typeBuffer, "?????????? ??????????????????????????????????")) {
            if(contains(buffer, "A++")) {
                energyClass = APP;
            }
            else if(contains(buffer, "A+")) {
                energyClass = AP;
            }
            else if(contains(buffer, "A")) {
                energyClass = A;
            }
            else if(contains(buffer, "E")) {
                energyClass = E;
            }
        }
        else if(contains(typeBuffer, "?????????? ???????????????? ??????????")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%f", &capacity);
            free(gl);
        }
        else if(contains(typeBuffer, "?????????????? No Frost")) {
            if(contains(buffer, "????????")) {
                noFrost = 1;
            }
        }
        else if(contains(typeBuffer, "????????????")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%f", &height);
            free(gl);
        }
        else if(contains(typeBuffer, "????????????")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%f", &width);
            free(gl);
        }
        else if(contains(typeBuffer, "???????????????????? ?????????????????? ?????????????????????? ????????????")) {
            char* gl = getLeft(buffer);
            sscanf(gl, "%d", &cameraCount);
            free(gl);
        }
        else if(contains(typeBuffer, "????????")) {
            snprintf(color, sizeof(color), "%s", buffer);
        }
        descPtr = findString(descPtr, "<td class='result__attr_var");
    }
    ptr = findString(ptr, "<span data-code=\"");
    getTagText(ptr, buffer);
    removeSpaces(buffer);
    sscanf(buffer, "%f", &price);
    (*refrigerators)[currPos] = init(name, price,controlType,compressorCount,energyClass,capacity,noFrost,height,width,cameraCount,color);
}

void htmlParse(Refrigerator** refrigerators, int* size) {
    char html[1000000]; char *ptr; char *start; const char *end;

    FILE *fp = fopen("/Users/aizyka/Documents/GitHub/BSUIR/????????/LAB2.1/test.html", "r");
    if (fp == NULL) {
        printf("Error: Failed to open URL.");
        return;
    }

    fread(html, 1, sizeof(html), fp);
    fclose(fp);

    start = findString(html, "<ul class=\"b-result\" id=\"j-result-page-");
    end = findString(start, "</ul>");

    ptr = start;
    int count = getCount(ptr, "<li class=\"result__item cr-result__full");
    *size = count;
    *refrigerators = (Refrigerator*) calloc(60, sizeof(Refrigerator));
    int currPos = 0;
    while (ptr < end) {
        ptr = findString(ptr, "<li class=\"result__item cr-result__full");
        if (ptr == NULL)
            break;
        char* localEnd = findString(ptr, "</li>");
        parseContent(ptr,localEnd,refrigerators,currPos);
        currPos++;
        ptr = localEnd;
    }
}