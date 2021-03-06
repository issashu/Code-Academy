/*
Задача 19.
Напишете програма, която да създаде стек (LIFO) от 16 елемента, който
има следното API
int pop()
void push()
int top()
int isFull()
*/

#include <stdio.h>
#include <stdlib.h>

int MaxRamAllowed = 1073741824;
extern int ClipBoard = 0;

// int CreateStack(int *StackPointer, int Size);
void push(int *StackPointer, int *Position);
void StackCounter (int *Position, int Direction);
int pop(int *StackPointer, int *Position);
int top(int *StackPointer, int *Position);
int isFull(int *StackPointer, int Size);

int main(){
    int MaxStackSize = 0;
    int StackPosition = 0;
    int Operation = 0;
    char Continue ='y';
    int *Stack = NULL;

    reallocation:
    printf("How big do you need the stack?\n");
    scanf("%d", &MaxStackSize);
    Stack = realloc (Stack, MaxStackSize*sizeof(int));
    if (Stack == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        goto reallocation;
    }
   // CreateStack(&Stack, MaxStackSize);
    
    printf("%p\n", Stack);
    printf("%d\n", MaxStackSize);

    while( Continue == 'y'){
        printf("Press 1 for adding an element on the stack or 2 for removing:\n");
        scanf("%d", &Operation);

        if (Operation == 1 && StackPosition == MaxStackSize){
            MaxStackSize *= 2;
            isFull(Stack, MaxStackSize);
            if(Stack==NULL){
                return 1;
            }
            else{
                push(Stack, &StackPosition);
                ClipBoard = top(Stack, &StackPosition);
            }
        }
        else if(Operation == 1 && StackPosition >= 0){
            push(Stack, &StackPosition);
            ClipBoard = top(Stack, &StackPosition);
        }
        else if(Operation == 2 && StackPosition > 0){
            pop(Stack, &StackPosition);
            ClipBoard = top(Stack, &StackPosition);
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

int top(int *StackPointer, int *Position){
    printf ("\nTop element of the stack is: ");
    printf ("%d\n", StackPointer[*Position-1]);
    printf("The value is saved to ClipBoard");

    return StackPointer[*Position-1];

}

int isFull(int *StackPointer, int Size){
    if (sizeof(StackPointer) >= MaxRamAllowed){
                printf("We are out of RAM dimension! May God have mercy on our CPUs!");
            }
            else{
                StackPointer = realloc (StackPointer, Size*sizeof(int));
            }
    StackPointer = realloc(StackCounter, Size*sizeof(int));
    if (StackPointer == NULL){ 
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        return 1;
    }
}