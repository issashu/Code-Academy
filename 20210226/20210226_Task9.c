/*
Задача 9. Изведете резултата от деленето на две цели
числа от тип int като double с преобразуване и без такова
*/

#include <stdio.h>

int main(){
    int Var1 = 65;
    int Var2 = 12;

    printf("Without cast: %lf \n", (Var1/Var2));
    printf("With cast: %lf \n", (double) Var1/Var2);
}