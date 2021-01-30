/*
Задача 8.Напишете прототипите на разгледаните досега функции 
int add(int a, int b) и int incr(int c) във файла f.h, a телата на функциите 
във файла f.c. и използвайте тези функции във файла m.c, където е разписано 
тялото на функцията main() . Компилирайте програмата по показания по-горе начин.
*/
#include <stdio.h>
#include "20210129_Task8_f.h"

extern double a = 0.00;
extern double b = 0.00;

int main(){
    printf("Please insert the lenght of the two sides of a triagnle:\n");
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf("The triangle area with the entered lenghts is: %lf\n", TriangleArea(a, b));
    printf("The triangle area with the entered lenghts is: %lf\n", SquareArea(TriangleArea(a, b)));
}