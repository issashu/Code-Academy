/*
Задача 6. Напишете функция с прототип my_swap(а, b), която разменя стойностите на две цели числа
без да използва спомагателна променлива (например: *a = *a + *b; *b = *a - *b; *a = *a - *b).
*/

#include <stdio.h>

int main(){
    int a = 0;
    int b = 0;
    int *p1 = &a;
    int *p2 = &b;

    printf("PLease enter two numbers for a and respectively b: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    p1 = b;
    p2 = a;

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", p1);
    printf("%p\n", p2);


    printf("Value of a is %d\n", p1);
    printf("Value of b is %d\n", p2);
}