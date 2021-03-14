/*
Задача 2. Прост пример за използване на масив: Реализация на класическия 
алгоритъм сито на Ератостен ( III век преди н. е.) за намиране на всички прости 
числа в интервал от 0 до n

https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Initialiser(int** Array, int MaxElements);
void Eratosten(int** Array, int MaxElements);
void Printer(int* Array, int MaxElements);

int main(){
    int* EratArray = NULL;
    int Number = 0;
    printf("Enter the number\n");
    scanf("%d",&Number);
    
    Initialiser(&EratArray,Number);
    Eratosten(&EratArray,Number);
    Printer(EratArray, Number);

    free(EratArray);
    return 0;
}

void Initialiser(int** Array, int MaxElements){
    *Array = calloc(MaxElements,sizeof(int));

    for(int i = 2; i<=MaxElements; i++){
        (*Array)[i] = i;
    }
}

void Eratosten(int** Array, int MaxElements){
    int i = 2;
    int j = 0;

    while ((i*i) <= MaxElements){
        if ((*Array)[i] != 0){
            for(j=2; j<MaxElements; j++){
                if ((*Array)[i]*j > MaxElements)
                    break;
                else
                    (*Array)[(*Array)[i]*j]=0;
            }
        }
        i++;
    }
}

void Printer(int* Array, int MaxElements){
    for(int i = 2; i<=MaxElements; i++){
        if (Array[i]!=0){
            printf("%d ",Array[i]);
        }
    }
    printf("\n");
}