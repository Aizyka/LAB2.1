#include "definitions.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

int checkArray(int size) {
    if(size <= 0)
    {
        printf("Error! Array not created\n");
        return 1;
    }
    return 0;
}

void Task4(Refrigerator** arr, int* sizeArr) {
    printf("Enter index: ");
    int index;
    while(!scanf("%d", &index) || index < 0 || index >= *sizeArr) {
        printf("Invalid index!\n");
        rewind(stdin);
        printf("Enter index: ");
    }
    removeFromArray(arr, sizeArr, index);
}

void menu() {
    int size = 0;
    Refrigerator* refrigerators;

    while(1) {
        printf("\nChoose Task:\n"
               "1 - Create array\n"
               "2 - Show array\n"
               "3 - Sort by fields\n"
               "4 - Remove struct from array\n"
               "5 - Parse HTML\n"
               "Your choice: ");
        int choice;
        while(!scanf("%d", &choice) || choice < 1 || choice > 5) {
            printf("Invalid choice! Valid choice [1-5]\n");
            rewind(stdin);
            printf("Your choice: ");
        }
        printf("\n");
        switch (choice) {
            case 1:
                if(size > 0)
                    free(refrigerators);
                fillArray(&refrigerators, &size);
                break;
            case 2:
                if(checkArray(size))
                    break;
                showArray(refrigerators,size);
                break;
            case 3:
                if(checkArray(size))
                    break;
                sort(refrigerators,size);
                break;
            case 4:
                if(checkArray(size))
                    break;
                Task4(&refrigerators, &size);
                break;
            case 5:
                htmlParse(&refrigerators,&size);
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}