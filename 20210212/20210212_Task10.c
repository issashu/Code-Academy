/*
 Задача 10*.
Реализация на масив с променлива размерност
Тази задача е подобна на задача 2, където използваме char масив. Тук може да използвате друг тип.

Тук условието не иска ли абсолютно същото като във всички други задачи с realloc? Ако да - кода е като на 9та задача.

За да има разлика все пак, питам юзъра, дали му трябват повече елементи, заделям ново място, копирам старите елементи
и освобождавам предишния пойнтер. Опасявам се, че е възможно да ми остава един пойнтер сочещ в нищото (*Point_Temp)

Не успявам обаче да изведа първоначалното заделяне на памет в отделна функция. Заделянето работи, но после въвеждането
на информация дава segmentation fault. Вероятно не се пренасочва пойнтера към заделените адреси поради
някаква призина...
*/

#include <stdio.h>
#include <stdlib.h>

int AllocateMemory (int *P, int uSize);
int FreeMemory(int *p);
int ReallocateMemory(int *p, int NrElements);
int EnterElements(int *p, int MaxElem);

int main(){
    //Variables go here:
    int NrElements = 2;
    char Answer = 'y';

    //Methods go here:
    printf("Please enter how many elements you need memory allocated for: \n");
    scanf("%d", &NrElements);
    int *Pointy = calloc(NrElements, sizeof(int));
    if (Pointy == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array allocated at %p up to %p\n", Pointy, (Pointy+NrElements));
    }
    EnterElements(Pointy, NrElements);
    printf("\n");
    printf("Do you require further space for entries?\n");
    if (Answer == 'y'){
        ReallocateMemory(Pointy, NrElements);
        for(int i=0; i < NrElements; i++){
            printf("%d ", Pointy[i]);
        }
    }
    FreeMemory(Pointy); 

}

int ReallocateMemory(int *p, int NrElements){
    int NewMax = 0;
    printf ("Please enter how many additonal elements you need for the array: \n");
    scanf ("%d", &NewMax);
    if(NewMax>NrElements){
       int *Point_Temp = calloc(NewMax, sizeof(int));
        if (Point_Temp == NULL){
            printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
            return 1;
        }
        for(int i=0; i<NrElements;i++){
            Point_Temp[i] = p[i];
        }
        printf("Please enter the new additional values:\n");
        for(int i=NrElements; i < NewMax; i++){
            scanf("%d", &p[i]);
        }
            
        for (int i=0; i<NewMax; i++){
            printf("%d ", Point_Temp[i]);
        }
    }
}

int EnterElements(int *p, int MaxElem){
    printf("Please enter the desired elements of the array:\n");
    for(int i=0; i < MaxElem; i++){
       scanf("%d", &p[i]);
    }
    printf("You entered the values:\n");
    for(int i=0; i < MaxElem; i++){
        printf("%d ", p[i]);
    }

}

int FreeMemory(int *p){
    free(p);
}