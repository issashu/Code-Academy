/*
Задача 2 Създайте нов потребителски тип
към тип long long int. Използвайте го във функцията
printf, отпечатайте размера.
*/

#include <stdio.h>
#include <stdlib.h>

typedef long long int LongInt;

int main(){
    LongInt Var1;
    long long int Var2;
    printf("The size of our new type LongInt is: %d\n", sizeof(Var1));
    printf("The size of long long int is: %d\n", sizeof(Var2));
}