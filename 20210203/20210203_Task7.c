/*
Задача 7. Дефинирайте масив int с 10 елемента. Дефинирайте пойнтер, който ще сочи към масива. 
Насочете пойнтера към масива. Нужно ли е да използвате &? Какво представлява името на масива? 
Какво сочи? Колко начина има за да изпишете насочването на пойнтера към масива. 
Има ли разлика между тях?
*/

#include <stdio.h>

int main(){
    int array[10] = {2};
    int *pointy1;
    int *pointy2;
    pointy1 = &array[0];
    pointy2 = array;

    printf("%d\n", *pointy1);
    printf("%d\n", *pointy2);
}