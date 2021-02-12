/*
 Задача 4.
Заделяне и освобождаване на памет - malloc, free. Заделете динамично памет за масив и попълнете елементите

Копирах си кода от първа задача. Преди това пробвах да направя отделни функции за всяко действие и глобална променлива,
Но дава seg fault, когато се опитва да впише елементи. Неработещия код съм оставил като коментар по-долу, за да го
пробвам по-късно.
*/

#include <stdio.h>
#include <stdlib.h>

int EnterElements(int *p, int MaxElem);
int CalcSum(int *p, int MaxElem);

int main(){
//Variables go here:
short NrElements = 0;

//Methods go here:
printf("Please enter how many elements do you need: \n");
scanf("%d", &NrElements);

int *Pointy = calloc(NrElements, sizeof(int));
if (Pointy == NULL){
    printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
    return 1;
}
EnterElements(Pointy, NrElements);

free(Pointy);
//return partameters go here (if any):

}

int EnterElements(int *p, int MaxElem){
    printf("Please enter the desired elements of the array:\n");
    for(int i=0; i < MaxElem; i++){
        scanf("%d", &p[i]);
    }

    for(int i=0; i < MaxElem; i++){
        printf("%d ", p[i]);
    }

}



/*
#include <stdio.h>
#include <stdlib.h>

int AllocateMemory (int *P, int uSize);
int FreeMemory(int *p);
int EnterValues(int *p, int MaxElem);

int main(){
    //Variables go here:
    int NrElements = 0;

    //Methods go here:
    printf("Please enter how many elements do you need: \n");
    scanf("%d", &NrElements);
    int *Pointy = AllocateMemory (Pointy, NrElements);
    EnterValues(Pointy, NrElements);
    FreeMemory(Pointy);  
}

int AllocateMemory (int *p, int uSize){
    p = calloc(uSize, sizeof(int));   
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

int EnterValues(int *p, int MaxElem){
    printf("Please enter the desired elements of the array:\n");
    for(int i=0; i < MaxElem; i++){
        scanf("%d", &p[i]);
    }

    for(int i=0; i < MaxElem; i++){
        printf("%d ", p[i]);
    }

}
*/