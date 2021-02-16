/*
 Задача 3.
Дефинирайте и инициализирайте три пойнтера, тип int, тип float, тип char.
*/
#include <stdio.h>

int main(){
    float Floatus = 2.34;
    char Array[10]= {'c'};
    int *PointyInt = NULL;
    float *PointyFloat = &Floatus;
    char *PointyChar = Array;

    printf("%.2f %d %c", *PointyFloat, *PointyInt, PointyChar[5]);
}