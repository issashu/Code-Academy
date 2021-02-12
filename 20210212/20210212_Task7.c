/*
 Задача 7.
Заделяне на памет с calloc
Заделете динамична памет за масив от елементи, като извикате функция, която нулира заделената памет.

Преписал съм си кода от първа задача, защото ползвах calloc там, вместо malloc.
*/

#include <stdio.h>
#include <stdlib.h>

int EnterElements(int *p, int MaxElem);

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