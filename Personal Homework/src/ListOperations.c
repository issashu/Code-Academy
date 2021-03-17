#include <stdio.h>
#include <stdlib.h>
#include "ListOperations.h"

/**
 * @brief The StartList function generates the initial head node of the list. 
 *        It requires a pointer to the allocated area for the head node.
 */
void SetupList(TDListNode** Head, TDListNode** Tail){
    printf("Please enter a value for the first element of the list: ");
    scanf("%d", &(*Head)->m_nValue);
    (*Head)->m_pNextNode = NULL;
    (*Head)->m_pPrevNode = NULL;
    *Tail = *Head;
    NodeCounter++;
}

void AddBeginning (TDListNode** Head){
    TDListNode* NewNode = (TDListNode*) malloc(sizeof(TDListNode));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    NewNode->m_pNextNode = *Head;
    NewNode->m_pPrevNode = NULL;
    (*Head)->m_pPrevNode = NewNode;
    *Head = NewNode;
    NodeCounter++;
}

void AddBetween(TDListNode* Head){
    short Position;
    KeyNode = Head;
    TDListNode* NewNode = (TDListNode*) malloc(sizeof(TDListNode));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    printf("What position do you need the value added: ");
    scanf("%hd", &Position);
    for(int i=0; i<Position-1; i++){
        KeyNode = KeyNode->m_pNextNode;
    }
    NewNode->m_pNextNode = KeyNode->m_pNextNode;
    KeyNode->m_pNextNode->m_pPrevNode = NewNode;
    NewNode->m_pPrevNode = KeyNode;
    KeyNode->m_pNextNode = NewNode;
}

void AppendEnd (TDListNode** Tail){
    /*while ((*Tail)->m_pNextNode != NULL) {
        *Tail = (*Tail)->m_pNextNode;
    }*/
    TDListNode* NewNode = (struct TDListNode*)malloc(sizeof(TDListNode));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    (*Tail)->m_pNextNode = NewNode;
    NewNode->m_pNextNode = NULL;
    NewNode->m_pPrevNode = (*Tail);
    *Tail = NewNode;
    NodeCounter++;
}

void RemoveNode(TDListNode* Head, TDListNode* Tail){
    short Position;
    KeyNode = Head;
    TDListNode* TempPoint=(TDListNode*)malloc(sizeof(TDListNode));
    printf("What position do you need the value removed from: ");
    scanf("%hd", &Position);
    //Itterates tot he node just before the one to delete
    for(int i=1; i<Position-1; i++){
        KeyNode = KeyNode->m_pNextNode;
    }
    TempPoint = KeyNode->m_pNextNode;
    KeyNode->m_pNextNode = TempPoint->m_pNextNode;
    free(TempPoint);
}

void RemoveEnd(TDListNode** Tail){
    KeyNode = (*Tail);
    (*Tail) = (*Tail)->m_pPrevNode;
    (*Tail)->m_pNextNode = NULL;
    free(KeyNode); 
    NodeCounter--;
}

void RemoveBegining(TDListNode** Head){
    KeyNode = (*Head);
    (*Head) = (*Head)->m_pNextNode;
    KeyNode->m_pNextNode = NULL;
    free(KeyNode); 
    NodeCounter--;
}

short Menu(short Selector){
    printf("Your list currently contsains %hd element(s).\n", NodeCounter);
    printf("What would you like to do next?\n");
    printf("1. Add element at the begining of the list.\n2. Add element after another element.\n3. Add element at the end of the list\n4.Print the list.\n5.Delete an element\n6.Quit program.\nInput: ");
    selection:
    scanf("%hd", &Selector);
    if (Selector<1 || Selector>6){
        printf("Incorrect selection, please select a number between 1 and 6!");
        goto selection;
    }
    return Selector;
}

void ListPrinter(TDListNode* Head){
    TDListNode* PrintPoint = Head;
    int i=0;
    printf("{");
    while(PrintPoint!=NULL){
        printf("\tThe %d element of list is: %d;\n", i+1, PrintPoint->m_nValue);
        PrintPoint = PrintPoint->m_pNextNode;
        i++;
    }
    printf("}\n");
}