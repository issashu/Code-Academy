/*Character navigates back and forth a train to solve a mystery. Waggons are linked in a doubly linked list
for the purpose of the exercise*/
//#include "ListOperations.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TDListNode { 
  int m_nValue; 
  struct TDListNode* m_pNextNode; 
  struct TDListNode* m_pPrevNode; 
} TDListNode;

static short NodeCounter = 0;

static TDListNode* Head;
static TDListNode* Tail;
static TDListNode* KeyNode;

void SetupList(TDListNode** Head, TDListNode** Tail);
void AddBeginning (TDListNode** Head);
void AppendEnd (TDListNode** Tail);
void AddBetween(TDListNode* Head);
void RemoveNode(TDListNode* Head);
void RemoveBegining(TDListNode** Head);
void RemoveEnd(TDListNode** Tail);
short Menu(short Selector);
void ListPrinter(TDListNode* Head);

int main(){
    short Selection = 0;
    Head = (TDListNode*)malloc(sizeof(TDListNode));
    SetupList(&Head, &Tail);
    while(Selection!=6){
        Selection = Menu(Selection);
        switch (Selection){
            case 1:
               AddBeginning(&Head);
            break;

            case 2:
                AddBetween(Head);
            break;

            case 3:
                AppendEnd(&Tail);
            break;

            case 4:
                ListPrinter(Head);
            break;

            case 5:
                RemoveNode(Head);
            break;

            case 6:
                printf("Have a nice day! See you soon!\n");
            break;
        }
    }
    return 0;
}
//============================================================================================

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

void RemoveNode(TDListNode* Head){
    short Position;
    KeyNode = Head;
    TDListNode* TempPoint=(TDListNode*)malloc(sizeof(TDListNode));
    printf("What position do you need the value removed from: ");
    scanf("%hd", &Position);
    //Itterates to the node just before the one to delete
    for(int i=1; i<Position-1; i++){
        KeyNode = KeyNode->m_pNextNode;
    }

    if (KeyNode==Head){
        RemoveBegining(&Head);
    }
    else if(KeyNode==Tail){
        RemoveEnd(&Tail);
    }
    else{
        TempPoint = KeyNode->m_pNextNode;
        KeyNode->m_pNextNode = TempPoint->m_pNextNode;
        free(TempPoint);
    }    
}

void RemoveEnd(TDListNode** Tail){
    if((*Tail)->m_pPrevNode!=NULL){
        KeyNode = (*Tail);
        (*Tail) = (*Tail)->m_pPrevNode;
        (*Tail)->m_pNextNode = NULL;
        free(KeyNode); 
        NodeCounter--;
    }
}

void RemoveBegining(TDListNode** Head){
    KeyNode = (*Head);
    (*Head) = (*Head)->m_pNextNode;
    (*Head)->m_pPrevNode = NULL;
    free(KeyNode); 
    NodeCounter--;
}

short Menu(short Selector){
    printf("Your list currently contsains %hd element(s).\n", NodeCounter);
    printf("What would you like to do next?\n");
    printf("1. Add element at the begining of the list.\n2. Add element after another element.\n");
    printf("3. Add element at the end of the list\n4.Print the list.\n5.Delete an element\n6.Delete at end\n");
    printf("7.Delete at beginning\n8.Quit program.\nInput: ");
    selection:
    scanf("%hd", &Selector);
    if (Selector<1 || Selector>8){
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

