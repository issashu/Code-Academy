/*
Задача 1. Да се направи програма, която заделя динамичен масив с брой елементи зададени от потребителя. 
За всеки елемент от масива се очаква потребителят да въведе цяло и число и след това се изчислява сумата 
на всички елементи от масива.
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
CalcSum(Pointy, NrElements);

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

int CalcSum(int *p, int MaxElem){
    int Sum =0;
    for(int i=0; i<MaxElem; i++){
        Sum += p[i];
    }

    printf("\nThe sum of all elements is: %d\n", Sum);

}