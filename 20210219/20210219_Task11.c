/*
Задача 11. Дефинирайте структура, в която има член указател към самата структура. 
Използвайте тази структура, за да дефинирате две променливи, които се указват една друга.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct PointerStr{
    int x;
    int y;
    struct PointerStr *Pointer;

} structure;

int main(){
    structure Struct1;
    structure Struct2;

    Struct1.x = 3;
    Struct1.y = 5;
    Struct2.x = 4;
    Struct2.y = 6;

    Struct1.Pointer = &Struct2;
    Struct2.Pointer = &Struct1;

    printf("%d %d %d %d\n", Struct2.Pointer->x, Struct1.Pointer->x, Struct2.Pointer->y, Struct1.Pointer->y);
}