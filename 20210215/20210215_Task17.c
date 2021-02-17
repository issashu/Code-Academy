/*
Задача 17. Направете същото, както в задача 18., но преди да
копирате, нулирайте стойността на стринговете, в
които ще копирате, използвайки готовата функция
memset. Потърсете онлайн как работи тази функция и
какви аргументи приема.
https://www.tutorialspoint.com/c_standard_library/c_functi
on_memset.htm
*/

#include <stdio.h>
#include <string.h>

int main(){
    char string1[] = "A string to be copied.";
    char string2[100];
    char string3[] = "I am very good in strings coping!";
    char string4[100];

    memset(string2,0,100);
    memset(string4,0,100);

    strcpy(string2, string1);
    strcpy(string4, string3);

    printf("%s\n", string2);
    printf("%s\n", string4);
}