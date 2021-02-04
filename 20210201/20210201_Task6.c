/*
Задача 6. Напишете функция, която изчислява произведението на числата от 1 до 30.
*/
#include <stdio.h>

int main(){
    long double a=1;

    for (int i=1; i<31; i++){
        a*=i;
    }

    printf("Multiplication of 1 through 30 is: %Lf", a);
}