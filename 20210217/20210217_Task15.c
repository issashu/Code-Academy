/*
Задача 15.
Напишете програма аналог на спортния тотализатор.
Използвайте функции.
Насоки:
1. Давате право на избор на играча да избере тотализатор, в който
ще си пробва късмета: (5 от 35), (6 от 42) или (6 от 49)
2. При всяко завъртане програмата изписва 1 произволно число,
което не е извадено до момента.
3. Програмата вади числата, нужни за избраната игра (5 или 6).

ИЗПОЛВАХ СИ КОДА ЗА СТАК
*/
//#include <unistd.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void push(int *StackPointer, int *Position);
void StackCounter (int *Position, int Direction);

int main(){
    int MaxStackSize = 49;
    int StackPosition = 0;
    int Operation = 0;
    char Continue ='y';
    int MaxRamAllowed = 1073741824;
    int *Stack = NULL;

    Stack = realloc (Stack, MaxStackSize*sizeof(int));
    if (Stack == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        return 1;
    }
    
    printf("%p\n", Stack);
    printf("%d\n", MaxStackSize);

    

    free (Stack);
}

/*int CreateStack(int *StackPointer, int Size){
    StackPointer = realloc(StackCounter, Size*sizeof(int));
    if (StackPointer == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
    }

    return *StackPointer;
}*/

void push(int *StackPointer, int *Position){
    int PushDirection = 1;
    int Element = 0;
    if(Position >=0){
        printf("В колелото бяха заредени %d топки с номера от 1 до %d")
        printf("Please enter a number to push to the stack:\n");
        scanf("%d", &Element);
        StackPointer[*Position] = Element;
        StackCounter(Position, PushDirection);
        printf("Stack currently contains:\n");
        for(int i = 0; i<*Position; i++){
            printf("%d, ", StackPointer[i]);
        }
    }
}

void StackCounter (int *Position, int Direction){
    *Position += Direction;
}