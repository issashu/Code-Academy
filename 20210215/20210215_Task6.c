/*
Задача 6

Дефинирайте променлива „а“, дeфинирайте пойнтер към нея, присвоете му адреса на променливата. 
През пойнтера задайте нова стойност = 5 на променливата „а“. Каква е стойността на “а”? - 5
*/

#include <stdio.h>

int main(){
    int *Pointy = NULL;
    int a = 0;
    Pointy = &a;
    *(Pointy) = 5;

    printf("%d", a);
}