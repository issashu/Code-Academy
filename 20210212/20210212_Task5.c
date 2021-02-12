/*
 Задача 5 Разширяване на заделена памет с realloc

  Кода е същия като при задача 3. Реално там също си правя realloc.
*/
#include <stdlib.h>
#include <stdio.h>

int AllocateMemory (int uSize);
int ReallocateMemory(int *p);
int FreeMemory(int *p);

int *Pointy;

int main(){
    //Variables go here:
    short NrElements = 0;

    //Methods go here:
    printf("Please enter how many elements do you need: \n");
    scanf("%d", &NrElements);
    AllocateMemory (NrElements);
    ReallocateMemory(Pointy);
    FreeMemory(Pointy);
}

int AllocateMemory (int uSize){
    int *Pointy = calloc(uSize, sizeof(int));   
    if (Pointy == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array allocated at %p up to %p\n", Pointy, (Pointy+uSize));
        return 0;
    }
}

int ReallocateMemory(int *p){
    int NewMax = 0;
    printf ("Please enter a new size for the array: \n");
    scanf ("%d", &NewMax);
    Pointy = realloc(p, NewMax * sizeof(int));
    if (Pointy == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array reallocated at %p up to %p\n", Pointy, (Pointy+NewMax));
        return 0;
    }
}

int FreeMemory(int *p){
    free(p);
}