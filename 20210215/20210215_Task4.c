/*
 Задача 4.
Дефинирайте пойнтер и опитайте да отпечатате стойността му на конзолата (%р) с printf.
Какво се визуализира?

 Адреса в паметта, където се намира пойнтера
*/

#include <stdio.h>

int main(){
    float Floatus = 2.34;
    float *PointyFloat = &Floatus;
    
    printf("%p", *PointyFloat);
}