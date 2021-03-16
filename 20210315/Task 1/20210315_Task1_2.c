#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task1.h"
/*Due to precedence of operators we need to use brackets, so 
derefferensing happens before the ->*/
void StartList(stek** Head){
    printf("Please enter a value for the first element of the stack: ");
    scanf("%d", &(*Head)->m_nValue);
    (*Head)->m_pNext = NULL;
    NodeCounter++;
}

void Push (stek** Head){
    int Temp=0;
    
    do{
        stek* NewNode = (stek*) malloc(sizeof(stek));
        printf("Enter value for the next element: ");
        scanf("%d", &Temp);
        NewNode->m_nValue = Temp;
        NewNode->m_pNext = *Head;
        *Head = NewNode;
        NodeCounter++;
    }while(Temp!=0);
}

void Pop(stek** Head){
    stek* TempPoint=(stek*)malloc(sizeof(stek));
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
    printf("1.Add elements\n2.Print the list.\n3.Delete an element\n4.Quit program.\nInput: ");
    selection:
    scanf("%hd", &Selector);
    if (Selector<1 || Selector>4){
        printf("Incorrect selection, please select a number between 1 and 6!");
        goto selection;
    }
    return Selector;
}

void ListPrinter(stek* Head){
    stek* PrintPoint = Head;
    int i=0;
    while(PrintPoint!=NULL){
        printf("%d  ", PrintPoint->m_nValue);
        PrintPoint = PrintPoint->m_pNext;
        i++;
    }
    printf("\n");
}