/*
 Задача 12
Напишете програма, която дефинира масив [10][10][10], пълни го със случайни числа 
и смята средното аритметично, само с един цикъл.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    srand(time(0));
    int array [10][10][10] = {0};
    int MaxCount = 1000;
    int *Pointy = &array;
    int Counter = 0;
    unsigned int total = 0;
    int average = 0;
    while (Counter < MaxCount){
        *Pointy = abs(rand());
        total += *Pointy;
        Pointy++;
        Counter++;
    }
    average = total/MaxCount;
    printf("The average: %d", average);
    return 0;
}