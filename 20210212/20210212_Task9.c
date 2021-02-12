/*
 Задача 9.
Разширяване на заделена памет с realloc
Напишете програма, която пита потребителя колко памет иска и заделя съответния блок памет. 
След това попитайте потребителя за нов размер и използвайте функция, която прави това.
*/

#include <stdio.h>
#include <stdlib.h>

int AllocateMemory (int *P, int uSize);
int FreeMemory(int *p);
int ReallocateMemory(int *p);

int main(){
    //Variables go here:
    int NrElements = 0;
    int *Pointy = NULL;

    //Methods go here:
    printf("Please enter how many elements you need memory allocated for: \n");
    scanf("%d", &NrElements);
    *Pointy = AllocateMemory (Pointy, NrElements);
    printf("Please enter a newe amount of memories to allocated memory for: \n");
    scanf("%d", &NrElements);
    ReallocateMemory(Pointy);
    FreeMemory(Pointy);  
}

int AllocateMemory (int *p, int uSize){
    p = (int*) calloc(uSize, sizeof(int));   
    if (p == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array allocated at %p up to %p\n", p, (p+uSize));
    }
}

int FreeMemory(int *p){
    free(p);
}

int ReallocateMemory(int *p){
    int NewMax = 0;
    printf ("Please enter a new size for the array: \n");
    scanf ("%d", &NewMax);
    p = realloc(p, NewMax * sizeof(int));
    if (p == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array reallocated at %p up to %p\n", p, (p+NewMax));
        return 0;
    }
}