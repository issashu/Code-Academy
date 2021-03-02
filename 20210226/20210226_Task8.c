/*
Задача 8.
Напишете програма, която да създаде стек (LIFO) по подобие на този
от лекция 18, който обаче да бъде реализиран с динамично с динамично
заделяне на памет съобразно желанието на потребителя с функциите
malloc(), и free(). Стека да има следните функции (следното API):

struct Stack{
    int *contents;
    int top;
};
Stack create(int size); void destroy(Stack s);
int pop(); void push()
int top()
int isFull(); int isEmpty(void)
*/

#include <stdio.h>
#include <stdlib.h>

int MaxRamAllowed = 1073741824;
extern int ClipBoard = 0;

struct Stack{
    int *contents;
    int top;
};

// struct Stack* CreateStack(struct Stack *StackPointer);
void push(struct Stack *StackPointer, int *Position);
void StackCounter (int *Position, int Direction);
int pop(struct Stack *StackPointer, int *Position);
int top(struct Stack *StackPointer, int *Position);
int isFull(struct Stack *StackPointer, int Size);
int isEmpty(void);

int main(){
    int MaxStackSize = 0;
    int StackPosition = 0;
    int Operation = 0;
    int AnswerLife = 0;
    char Continue ='y';
    struct Stack *StackPtr = NULL;

    reallocation:
    printf("How big do you need the stack?\n");
    scanf("%d", &MaxStackSize);
    StackPtr = realloc (StackPtr, sizeof(struct Stack));
    StackPtr->contents = calloc(MaxStackSize, sizeof(int));
    if (StackPtr == NULL || StackPtr->contents == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        goto reallocation;
    }
   // CreateStack(&Stack, MaxStackSize);
    
    for(int i=0; i<MaxStackSize; i++){
        printf("%p\n", &StackPtr->contents[i]);
    }
    printf("%d\n", MaxStackSize);

    while( Continue == 'y'){
        printf("Press 1 for adding an element on the stack or 2 for removing:\n");
        scanf("%d", &Operation);

        if (Operation == 1 && StackPosition == MaxStackSize){
            MaxStackSize *= 2;
            isFull(StackPtr, MaxStackSize);
            if(StackPtr==NULL){
                return 1;
            }
            else{
                push(StackPtr, &StackPosition);
                ClipBoard = top(StackPtr, &StackPosition);
            }
        }
        else if(Operation == 1 && StackPosition >= 0){
            push(StackPtr, &StackPosition);
            ClipBoard = top(StackPtr, &StackPosition);
        }
        else if(Operation == 2 && StackPosition > 0){
            pop(StackPtr, &StackPosition);
            ClipBoard = top(StackPtr, &StackPosition);
        }
        else if(Operation == 2 && StackPosition == 0){
            AnswerLife = isEmpty();
            if (AnswerLife == 42){
                printf("\n42");
            }
            
        }
        
        printf("\nDo you want to continue? (y for yes, anykey for no)\n");
        scanf (" %c", &Continue);
        // space before % to counter whatever retarded C buffer enter goes in....
    }

    printf("\nThank you traveling with Bearlines in RAM Space! Have a nice day!\n");

    free (StackPtr);
}

/*struct Stack* CreateStack(struct Stack *StackPointer){
    reallocation:
    printf("How big do you need the stack?\n");
    scanf("%d", &MaxStackSize);
    StackPtr = realloc (StackPtr, sizeof(struct Stack));
    StackPtr->contents = calloc(MaxStackSize, sizeof(int));
    if (StackPtr == NULL || StackPtr->contents == NULL){
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        goto reallocation;
    }
    return *StackPointer;
}*/

void push(struct Stack *StackPointer, int *Position){
    int PushDirection = 1;
    int Element = 0;
    if(Position >=0){
        printf("Please enter a number to push to the stack:\n");
        scanf("%d", &Element);
        StackPointer->contents[*Position] = Element;
        StackCounter(Position, PushDirection);
        printf("Stack currently contains:\n");
        for(int i = 0; i<*Position; i++){
            printf("%d, ", StackPointer->contents[i]);
        }
    }
}

int pop(struct Stack *StackPointer, int *Position){
    int PopDirection = -1;
    if (Position >= 0){
        StackPointer->contents[*Position] = '\0';
        StackCounter(Position, PopDirection);
    }
    printf("Stack currently contains:\n");
        for(int i = 0; i<*Position; i++){
            printf("%d, ", StackPointer->contents[i]);
        }
}

void StackCounter (int *Position, int Direction){
    *Position += Direction;
}

int top(struct Stack *StackPointer, int *Position){
    StackPointer->top = StackPointer->contents[*Position-1];
    printf ("\nTop element of the stack is: ");
    printf ("%d\n", StackPointer->top);
    printf("The value is saved to ClipBoard");

    return StackPointer->top;

}

int isFull(struct Stack *StackPointer, int Size){
    if (sizeof(StackPointer->contents) >= MaxRamAllowed){
                printf("We are out of RAM dimension! Call S.W.A.P and may God have mercy on our HDDs!");
            }
            else{
                StackPointer->contents = realloc (StackPointer->contents, Size*sizeof(int));
            }
    StackPointer = realloc(StackCounter, Size*sizeof(int));
    if (StackPointer == NULL){ 
        printf("Memory allocation BSoD! Restart OS and try again!\n");
        return 1;
    }
}

int isEmpty(void){
    printf("Stack is empty. Nothing to remove!");

    return 42;
}