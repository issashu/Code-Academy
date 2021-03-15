/*
Задача 3.
Направете едносвързан списък, съдържащ числата 1-14 и 
принтирайте петия елемент от края му.
*/
#include <stdio.h>
#include <stdlib.h>

static short NodeCounter = 0;
static const short Maxnumber = 14;

typedef struct node_t{ 
    int m_nValue; 
    struct node_t* m_pNext; 
}node_t;  

static node_t* Head;
static node_t* Tail;

void StartList(node_t** Head);
void ListPrinter(node_t* Head);

int main(){
    Tail = Head;
    StartList(&Head);
    ListPrinter(Head);
}

/*Due to precedence of operators we need to use brackets, so 
derefferensing happens before the ->*/
void StartList(node_t** Head){
    printf("Filling out the list with numbers ...\n");
    *Head = (node_t*)malloc(sizeof(node_t));
    (*Head)->m_nValue = 14;
    (*Head)->m_pNext = NULL;
    for (int i = 14; i> 1; i--){
        node_t* NewNode = (node_t*) malloc(sizeof(node_t));
        NewNode->m_nValue = (i-1);
        NewNode->m_pNext = *Head;
        *Head = NewNode;
        NodeCounter++;
    }
}

void ListPrinter(node_t* Head){
    node_t* PrintPoint = Head;
    printf("The list contains, the numbers: ");
    while(PrintPoint!=NULL){
        printf("%d ", PrintPoint->m_nValue);
        PrintPoint = PrintPoint->m_pNext;
    }
    PrintPoint = Head;
    NodeCounter -= 4;
    while(NodeCounter!=0){
        PrintPoint = PrintPoint->m_pNext;
        NodeCounter--;
    }
    printf("\n");
    printf("The 5th node from the end is: %d\n", PrintPoint->m_nValue);
}