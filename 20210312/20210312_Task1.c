/*
Задача 1. Реализация на списък. Напишете програма, която добавя и 
изтрива елемент от списък по позиция в списъка. Използвайте следния 
елемент на динамичния списък:
typedef struct t_node { 
int m_nValue; 
t_node* m_pNext; 
} t_node; 

https://www.learn-c.org/en/Linked_lists
*/
#include <stdio.h>
#include <stdlib.h>

static short NodeCounter = 0;
//typedef struct node_t node_t;
typedef struct node_t{ 
    int m_nValue; 
    struct node_t* m_pNext; 
}node_t;  

/*I have decided to close the list to current file for now*/
static node_t* Head;
static node_t* Tail;
static node_t* KeyNode;

/*In order to work on a pointer, we use double pointer and dereference it once
or we use single pointer and return it*/
void StartList(node_t** Head);
void AddBeginning (node_t** Head);
void AppendEnd (node_t** Tail);
void AddBetween(node_t* Head);
void RemoveNode(node_t* Head);
short Menu(short Selector);
void ListPrinter(node_t* Head);

int main(){
    short Selection = 0;
    Head = (node_t*)malloc(sizeof(node_t));
    StartList(&Head);
    Tail = Head;
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

/*Due to precedence of operators we need to use brackets, so 
derefferensing happens before the ->*/
void StartList(node_t** Head){
    printf("Please enter a value for the first element of the list: ");
    scanf("%d", &(*Head)->m_nValue);
    (*Head)->m_pNext = NULL;
    NodeCounter++;
}

void AddBeginning (node_t** Head){
    node_t* NewNode = (node_t*) malloc(sizeof(node_t));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    NewNode->m_pNext = *Head;
    *Head = NewNode;
    NodeCounter++;
}

void AddBetween(node_t* Head){
    short Position;
    KeyNode = Head;
    node_t* NewNode = (node_t*) malloc(sizeof(node_t));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    printf("What position do you need the value added: ");
    scanf("%hd", &Position);
    for(int i=0; i<Position-1; i++){
        KeyNode = KeyNode->m_pNext;
    }
    NewNode->m_pNext = KeyNode->m_pNext;
    KeyNode->m_pNext = NewNode;
}

void AppendEnd (node_t** Tail){
    while ((*Tail)->m_pNext != NULL) {
        *Tail = (*Tail)->m_pNext;
    }
    node_t* NewNode = (struct node_t*)malloc(sizeof(node_t));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    (*Tail)->m_pNext = NewNode;
    NewNode->m_pNext = NULL;
    *Tail = NewNode;
    NodeCounter++;
}

/*ALTERNATIVE append:
void PushBack(node_t** Tail){
    while ((*Tail)->next != NULL) {
        *Tail = (*Tail)->next;
    }

    (*Tail)->next = (node_t *) malloc(sizeof(node_t));
    (*Tail)->next->m_nValue = value;
    (*Tail)->next->next = NULL;
}
*/
void RemoveNode(node_t* Head){
    short Position;
    KeyNode = Head;
    node_t* TempPoint=(node_t*)malloc(sizeof(node_t));
    printf("What position do you need the value removed from: ");
    scanf("%hd", &Position);
    //Itterates tot he node just before the one to delete
    for(int i=1; i<Position-1; i++){
        KeyNode = KeyNode->m_pNext;
    }
    TempPoint = KeyNode->m_pNext;
    KeyNode->m_pNext = TempPoint->m_pNext;
    free(TempPoint);
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

void ListPrinter(node_t* Head){
    node_t* PrintPoint = Head;
    int i=0;
    printf("{");
    while(PrintPoint!=NULL){
        printf("\tThe %d element of list is: %d;\n", i+1, PrintPoint->m_nValue);
        PrintPoint = PrintPoint->m_pNext;
        i++;
    }
    printf("}\n");
}