/*
Задача 10. Напишете програма на С, която съдържа 3 функции, изнесете прототипите им в отделен .h файл.
1. Първата функция да калкулира най-малко общо кратно на две положителни числа.
2. Втората функция връща абсолютна стойност на числата (положителната стойност на числата).
a. Трябва да може да приеме като параметър float и да върне float.
b. Тествайте с инт и float.
3. Напишете функция, която калкулира корен квадратен от число.
a. Проверете дали резултатът е отрицателно число и върнете -1.
b. Използвайте втората си функция, за да обърнете числото в положително и
да намерите корен квадратен от него.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "20210129_Task10.h"

extern double number1;
extern double number2;

int main(){

    printf("Please first enter two numbers separated by a new line (Enter key): \n");
    scanf("%lf", &number1);
    scanf("%lf", &number2);

    Menu();
    printf("%lf", number1);
    printf("%lf", number2);
}

void Menu(){
    char answer=1;
    printf("Please select a desired operation to execute with the numbers:\n");
    printf(" 1. Least common multiplayer.\n 2.Absolute value.\n 3.Square root.\n");
    scanf("%c", &answer);

    switch (answer){
        case 1:
            LeastCommon(number1, number2);
        case 2:
            Modul((int) number1, (int) number2);


    }

}

double LeastCommon(double n1, double n2){
    double max;

    max = (n1 > n2) ? n1 : n2;

    while (1) {
        if (((int)max%(int)n1) == 0 && ((int)max%(int)n2) == 0) {
            printf("The LCM of %d and %d is %d.\n", n1, n2, max);
            break;
        }
        ++max;
    }

    return max;
}

int Modul(int n1, int n2){
    printf ("The absolute value of the first number %d is: %d\n", n1, abs(n1));
    printf ("The absolute value of the second number %d is: %d\n", n2, abs(n2));
}

int SQRT(double n1, double n2){
    if (n1<0){
        printf("Only positive numbers accepted. Comverting yours...\n");
        sleep(1);
        n1*=-1;
    }
    if (n2<0){
        printf("Only positive numbers accepted. Comverting yours...\n");
        sleep(1);
        n2*=-1;
    }
    printf("The square root of number %lf is: %lf\n", n1, sqrt(n1));
    printf("The square root of number %lf is: %lf\n", n2, sqrt(n2));

}