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
    int *p = &array;
    int i = 0, sum = 0;
    while (i < 1000){
        *p = rand();
        sum += *p;
        printf("on pos %d is generated number: %d\n", i+1, *p);
        p++;
        i++;
    }
    printf("The average: %d", sum/1000);
    return 0;
}