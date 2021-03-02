/*
Задача 11. тайпдефната структура node, съдържаща един член от
тип инт и един пойнтер към тип самата структура. Заделете динамично
памет за тази структура с malloc по описания по-горе начин.

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int PointA;
    struct node *Pointer;
} node;

int main(){
    node *Struktura = (node*)calloc(1,sizeof(node));
    printf("The struct node has been created and its size is: %d\n", sizeof(Struktura));
}