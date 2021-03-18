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

static TDListNode* gHead;
static TDListNode* gTail;
static TDListNode* KeyNode;

void SetupList(TDListNode** Head, TDListNode** Tail);
void AddBeginning (TDListNode** Head);
void AppendEnd (TDListNode** Tail);
void AddBetween(TDListNode* Head);
void RemoveNode(TDListNode** Head, TDListNode** Tail);
//void RemoveBegining(TDListNode** Head);
//void RemoveEnd(TDListNode** Tail);
short DevMenu(short Selector);
void ListPrinter(TDListNode* Head);

int main(){
    short Selection = 0;
    gHead = (TDListNode*)malloc(sizeof(TDListNode));
    SetupList(&gHead, &gTail);
    while(Selection!=6){
        Selection = DevMenu(Selection);
        switch (Selection){
            case 1:
               AddBeginning(&gHead);
            break;

            case 2:
                AddBetween(gHead);
            break;

            case 3:
                AppendEnd(&gTail);
            break;

            case 4:
                RemoveNode(&gHead, &gTail);
            break;

            case 5:
                ListPrinter(gHead);
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
    short KeyValue;
    KeyNode = Head;
    TDListNode* NewNode = (TDListNode*) malloc(sizeof(TDListNode));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    printf("What KeyValue do you need the value added: ");
    scanf("%hd", &KeyValue);
    for(int i=0; i<KeyValue-1; i++){
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

void RemoveNode(TDListNode** Head, TDListNode** Tail){
    short KeyValue = 0;
    KeyNode = (*Head);
    TDListNode* PrevPoint=(TDListNode*)malloc(sizeof(TDListNode));
    TDListNode* NextPoint=(TDListNode*)malloc(sizeof(TDListNode));
    printf("What value do you want deleted: ");
    scanf("%hd", &KeyValue);
    //Itterates to the node just before the one to delete
    while(KeyNode->m_nValue!=KeyValue){
        if(KeyNode->m_pNextNode==NULL){
            printf("No node ocntains the value %d\n", KeyValue);
            return;
        }
        else{
            KeyNode = KeyNode->m_pNextNode;
        }
    }
    if (KeyNode==(*Head)){
        if((*Head)->m_pPrevNode==NULL && (*Head)->m_pNextNode==NULL){
            printf("List is empty now\n");
            (*Head)=NULL;
            NodeCounter = 0;
        }
        else{
            (*Head) = (*Head)->m_pNextNode;
            (*Head)->m_pPrevNode = NULL;
            free(KeyNode); 
            NodeCounter--;
        }
    }
    else if(KeyNode==Tail){
        if((*Tail)->m_pPrevNode!=NULL){
            KeyNode = (*Tail);
            Tail = (*Tail)->m_pPrevNode;
            (*Tail)->m_pNextNode = NULL;
            free(KeyNode); 
            NodeCounter--;
        }
    }

    else{
        NextPoint = KeyNode->m_pNextNode;
        PrevPoint = KeyNode->m_pPrevNode;
        PrevPoint->m_pNextNode = NextPoint;
        NextPoint->m_pPrevNode = PrevPoint;
        free(KeyNode);
    }    
}

short DevMenu(short Selector){
    printf("****DEVELOPER MENU****\n");
    printf("Your list currently contsains %hd element(s).\n", NodeCounter);
    printf("1. Add element at the begining of the list.\n2. Add element after another element.\n");
    printf("3. Add element at the end of the list\n4.Delete an element\n5.Print the list.\n6.Quit program.\nInput: ");
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
    if(Head==NULL){
        printf("The List is empty!\n");
    }
    printf("{");
    printf("\tThe %d element of list is: %d;\n", i+1, PrintPoint->m_nValue);
    i++;
    while(PrintPoint->m_pNextNode!=NULL){
        PrintPoint = PrintPoint->m_pNextNode;
        printf("\tThe %d element of list is: %d;\n", i+1, PrintPoint->m_nValue);
        i++;
    }
    printf("}\n");
}

