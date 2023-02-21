#include <stdio.h>
#include "struct.h"
Refrigerator init(char name[100], float price, int controlType, int compressorCount, int energyClass, float capacity, int noFrost, float height, float width, int cameraCount, char color[25]) {
    Refrigerator product;
    snprintf(product.name, sizeof(product.name), "%s", name);
    product.price = price;
    product.controlType = controlType;
    product.compressorCount = compressorCount;
    product.energyClass = energyClass;
    product.capacity = capacity;
    product.noFrost = noFrost;
    product.height = height;
    product.width = width;
    product.cameraCount = cameraCount;
    snprintf(product.color, sizeof(product.color), "%s", color);
    return product;
}