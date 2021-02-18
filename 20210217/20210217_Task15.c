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
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void push(int *StackPointer, int *Position, int MaxNumber);
int GameSelector (void);
void StackCounter (int *Position, int Direction);

int main(void){
    int GameNr = 1;
    int MaxStackSize = 35;
    int NumbersDrawn =  5;
    int StackPosition = 0;
    int Operation = 0;
    char Continue ='y';
    int *Stack = NULL;

    GameNr = GameSelector();
    switch (GameNr){
        case 1:
            MaxStackSize = 35;
            NumbersDrawn =  5;
            break;
        
        case 2:
            MaxStackSize = 42;
            NumbersDrawn =  6;
            break;

        case 3:
            MaxStackSize = 49;
            NumbersDrawn =  6;
            break;
    }
    Stack = realloc (Stack, NumbersDrawn*sizeof(int));
    if (Stack == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        return 1;
    }
    printf("Dobar vecher dragi zriteli!\n");
        sleep(2);
        printf("V koleloto biaha zaredeni %d topki s nomera ot 1 do %d\n", MaxStackSize, MaxStackSize);
        sleep(2);
        printf("Eto te veche sa v sferata i se razbarkvat!\n");
        sleep(4);
    for (int i = 0; i<NumbersDrawn; i++){
        push(Stack, &StackPosition, MaxStackSize);    
    }
    printf("\nIzteglenite chisla do tuk v igrata sa:\n");
        for(int i = 0; i<StackPosition; i++){
            printf("%d ", Stack[i]);
        }
    sleep(1);
    printf("\nChestito na vsichki pechelivshi!");
    free (Stack);
}

/*int CreateStack(int *StackPointer, int Size){
    StackPointer = realloc(StackCounter, Size*sizeof(int));
    if (StackPointer == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
    }

    return *StackPointer;
}*/

int GameSelector (void){
    int Answer = 1;
    printf("Molia, izberete tiraj:\n");
    printf("1. (5 ot 35), 2.(6 ot 42) ili 3.(6 ot 49)\n");
    scanf("%d", &Answer);
    return Answer;
}

void push(int *StackPointer, int *Position, int MaxNumber){
    srand(time(0));
    int PushDirection = 1;
    int Element = 0;
    int i =rand()%4;
    char Dialogs[4][30] = {"Izteglenoto chislo e:", "Sledvashtoto chislo e:", "Izteglena be topka s nomer:", "Novoto chislo e:"};
    if(Position >=0){
        draw:
        Element = rand()%MaxNumber;
        for(int i=0; i<*Position; i++){
            if(Element == StackPointer[*Position]){
                goto draw;
            }
        }
        StackPointer[*Position] = Element;
        StackCounter(Position, PushDirection);
        printf(" %s", Dialogs[i]);
        printf("%d\n", Element);
        sleep(2);
    }
}

void StackCounter (int *Position, int Direction){
    *Position += Direction;
}