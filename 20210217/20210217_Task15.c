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
#include <time.h>

void push(int *StackPointer, int *Position, int MaxNumber);
int GameSelector (void);
void StackCounter (int *Position, int Direction);

int main(){
    int GameNr = 1;
    int MaxStackSize = 49;
    int StackPosition = 0;
    int Operation = 0;
    char Continue ='y';
    int *Stack = NULL;

    GameNr = GameSelector();
    switch (GameNr){
        
    }



    Stack = realloc (Stack, MaxStackSize*sizeof(int));
    if (Stack == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        return 1;
    }

    
    printf("На печелившите - честито!");
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
    printf("Моля, изберете, в коя игра ще участвате:\n");
    printf("1. (5 от 35), 2.(6 от 42) или 3.(6 от 49)\n");
    scanf("%d", &Answer);
    return Answer;
}

void push(int *StackPointer, int *Position, int MaxNumber){
    srand(time(0));
    int PushDirection = 1;
    int Element = 0;
    char Dialogs[] = {"И ето, че бе изтеглено числото", "Следващото изтеглено число е", "Бе изтеглена топка с номер", "Новото число е"};
    if(Position >=0){
        printf("Добър вечер, драги зрители!");
        sleep(0.5);
        printf("В колелото бяха заредени %d топки с номера от 1 до %d\n", MaxNumber, MaxNumber);
        sleep(0.5);
        printf("Ето те са вече в сферата и започват да се разбъркват!\n");
        sleep(1.5);
        StackPointer[*Position] = Element;
        StackCounter(Position, PushDirection);
        printf("%s\n", Dialogs[rand()%4-1]);
        sleep(0.5);
        printf("\nИзтеглените числа до тук в играта са:\n");
        for(int i = 0; i<*Position; i++){
            printf("%d, ", StackPointer[i]);
        }
    }
}

void StackCounter (int *Position, int Direction){
    *Position += Direction;
}