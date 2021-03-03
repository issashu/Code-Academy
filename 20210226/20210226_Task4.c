/*
Задача 4 Дефинирайте функция, която събира
две променливи и приема и изпълнява предефиниран
указател, като стойност.
*/
#include <stdio.h>
#include <stdlib.h>

typedef int* intptr;

int Addition(intptr Var1, intptr Var2);

int main(){
    int Var1 = 5;
    int Var2 = 6;
    intptr pVar1 = NULL;
    intptr pVar2 = NULL;
    intptr pResult = NULL;
    
    pVar1 = &Var1;
    pVar2 = &Var2;
    printf("The result is: %d", Addition(pVar1, pVar2));
}

int Addition(intptr Var1, intptr Var2){
    return *Var1+*Var2;
}