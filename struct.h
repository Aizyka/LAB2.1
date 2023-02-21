#ifndef LAB2_1_STRUCT_H
#define LAB2_1_STRUCT_H

enum ControlType{
    NONEControl,
    ElectricSensor,
    ElectricButton,
    Mechanic
};

enum EnergyClass {
    NONEClass,
    APP,
    AP,
    A,
    E
};


typedef struct {

    char name[100];
    float price;
    enum ControlType controlType;
    int compressorCount;
    enum EnergyClass energyClass;
    float capacity;
    int noFrost;
    float height;
    float width;
    int cameraCount;
    char color[25];
} Refrigerator;
#endif //LAB2_1_STRUCT_H
