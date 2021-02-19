/*
Задача 4.
Напишете две функции:
void push(int) (добавя елемент на края на стека) и
int pop() (премахва елемент от края на стека)
за стек с дълбочина 16 (може да се използва масив от 16 елемента от
тип int).
Проверете дали функциите работят коректно във функция main, като
добавите 15 елемента и след това ги извадите от стека и ги изведете на
екрана.

Ако искаме Queue, тогава си правим FIFO вместо LIFO

*/
#include <stdio.h>
#include <stdlib.h>



void CreateStack(int **StackPointer, int Size);
void push(int *StackPointer, int *Position);
void StackCounter (int *Position, int Direction);
int pop(int *StackPointer, int *Position);

int main(){
    int MaxStackSize = 0;
    int StackPosition = 0;
    int Operation = 0;
    char Continue ='y';
    int MaxRamAllowed = 1073741824;
    int *Stack = NULL;

    reallocation:
    printf("How big do you need the stack?\n");
    scanf("%d", &MaxStackSize);
    CreateStack(&Stack, MaxStackSize);
   // Stack = realloc (Stack, MaxStackSize*sizeof(int));
    if (Stack == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        goto reallocation;
    }
    
    printf("%p\n", Stack);
    printf("%d\n", MaxStackSize);

    while( Continue == 'y'){
        printf("Press 1 for adding an element on the stack or 2 for removing:\n");
        scanf("%d", &Operation);

        if (Operation == 1 && StackPosition == MaxStackSize){
            MaxStackSize *= 2;
            if (sizeof(Stack) >= MaxRamAllowed){
                printf("We are out of RAM dimension! May God have mercy on our CPUs!");
            }
            else{
                Stack = realloc (Stack, MaxStackSize*sizeof(int));
                push(Stack, &StackPosition);
            }
            
        }
        else if(Operation == 1 && StackPosition >= 0){
            push(Stack, &StackPosition);
        }
        else if(Operation == 2 && StackPosition > 0){
            pop(Stack, &StackPosition);
        }
        else if(Operation == 2 && StackPosition == 0){
            printf("Stack is empty. Nothing to remove!");
        }
        
        printf("\nDo you want to continue? (y for yes, anykey for no)\n");
        scanf (" %c", &Continue);
        // space before % to counter whatever retarded C buffer enter goes in....
    }

    printf("\nThank you traveling with Bearlines in RAM Space! Have a nice day!\n");

    free (Stack);
}

    void CreateStack(int **StackPointer, int Size){
    *StackPointer = (int*) realloc(*StackPointer, Size*sizeof(int));
    if (StackPointer == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
    }
    return StackPointer;
}

void push(int *StackPointer, int *Position){
    int PushDirection = 1;
    int Element = 0;
    if(Position >=0){
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

int pop(int *StackPointer, int *Position){
    int PopDirection = -1;
    if (Position >= 0){
        StackPointer[*Position] = '\0';
        StackCounter(Position, PopDirection);
    }
    printf("Stack currently contains:\n");
        for(int i = 0; i<*Position; i++){
            printf("%d, ", StackPointer[i]);
        }
}

void StackCounter (int *Position, int Direction){
    *Position += Direction;
}