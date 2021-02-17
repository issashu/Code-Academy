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

int CreateStack(int *StackPointer, int Size);
void push(int *StackPointer, int Element, int Size);
void StackCounter (int *Position, int Direction);
int pop();

int main(){
    int MaxStackSize = 12;
    int StackPosition = 0;
    int *Stack = NULL;

    printf("SO: %p\n", Stack);
    printf("SO: %d\n", MaxStackSize);
    printf("How big do you need the stack?\n");
    scanf("%d", MaxStackSize);
    *Stack = calloc(MaxStackSize, sizeof(int));
    if (Stack == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
    }
    //CreateStack(&Stack, MaxStackSize);
    
    printf("%p\n", Stack);
    printf("%d\n", MaxStackSize);
}

int CreateStack(int *StackPointer, int Size){
    *StackPointer = calloc(Size, sizeof(int));
    if (StackPointer == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
    }

    return *StackPointer;
}

void push(int *StackPointer, int Element, int Size){
    int AddDirection = 1;

    
}

int pop(){
    int PopDirection = -1;

}

void StackCounter (int *Position, int Direction){
    *Position += Direction;
}