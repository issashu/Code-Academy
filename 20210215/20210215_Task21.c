/*
Задача 21. Напишете функция, която сортира лексикографски масив от
символи (char[]) използвайки qsort.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparefunc (const void * a, const void * b);

int main(){
    char string[] = "I am very good in strings coping!";
    
    printf("Before sorting the string is: \n");
    printf("%s\n", string);

    qsort(string, sizeof(string)/sizeof(string[0]), sizeof(char), comparefunc);

    printf("\nAfter sorting the string is: \n");
    printf("%s\n", string);
}

int comparefunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}