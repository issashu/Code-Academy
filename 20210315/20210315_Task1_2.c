#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task1.h"
/*Due to precedence of operators we need to use brackets, so 
derefferensing happens before the ->*/
void StartList(stack_t** Head){
    printf("Please enter a value for the first element of the stack: ");
    scanf("%d", &(*Head)->m_nValue);
    (*Head)->m_pNext = NULL;
    NodeCounter++;
}

void Push (stack_t** Head){
    stack_t* NewNode = (stack_t*) malloc(sizeof(stack_t));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    NewNode->m_pNext = *Head;
    *Head = NewNode;
    NodeCounter++;
}

void Pop(stack_t** Head){
    stack_t* TempPoint=(stack_t*)malloc(sizeof(stack_t));
    //Itterates tot he node just before the one to delete
    TempPoint = (*Head);
    *Head=(*Head)->m_pNext;
    free(TempPoint);
    NodeCounter--;
    if (NodeCounter==0){
        printf("Stack is empty.");
    }
}

short Menu(short Selector){
    printf("Your stack currently contains %hd element(s).\n", NodeCounter);
    printf("What would you like to do next?\n");
    printf("1. Add element\n2.Print the list.\n3.Delete an element\n4.Quit program.\nInput: ");
    selection:
    scanf("%hd", &Selector);
    if (Selector<1 || Selector>6){
        printf("Incorrect selection, please select a number between 1 and 6!");
        goto selection;
    }
    return Selector;
}

void ListPrinter(stack_t* Head){
    stack_t* PrintPoint = Head;
    int i=0;
    printf("{");
    while(PrintPoint!=NULL){
        printf("\tThe %d element of list is: %d;\n", i+1, PrintPoint->m_nValue);
        PrintPoint = PrintPoint->m_pNext;
        i++;
    }
    printf("}\n");
}