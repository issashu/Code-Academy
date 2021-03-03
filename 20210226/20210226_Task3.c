/*
Задача 3. Дефинирайте потребителски тип към
указател. Създайте променлива, насочете указателя
към нея, използвайки новия потребителски тип.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int* intptr;

int main(){
    intptr Var1;
    int Var2 = 5;
    Var1 = &Var2;
    printf("Var2 before operations:%d\n", Var2);
    printf("Var2 after operations:%d\n", *Var1+5);
}