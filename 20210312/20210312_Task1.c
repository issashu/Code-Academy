/*
Задача 1. Реализация на списък. Напишете програма, която добавя и 
изтрива елемент от списък по позиция в списъка. Използвайте следния 
елемент на динамичния списък:
typedef struct t_node { 
int m_nValue; 
t_node* m_pNext; 
} t_node; 

WORK INPROGRESS
*/
#include <stdio.h>
#include <stdlib.h>

static short NodeCounter = 0;
typedef struct node node;
typedef struct node{ 
    int m_nValue; 
    struct node* m_pNext; 
}node;  

/*I have decided to close the list to current file for now*/
static node* Head;
static node* PrevNode;
static node* NextNode;


node* StartList(node* Head);
node* AddBeginning (node* Head);
void AppendEnd (node* PrevNode);
void AddBetween(node* PrevNode, node* NextNode);
short Menu(short Selector);
void ListPrinter(node* Head);

int main(){
    short Selection = 0;
    Head = (node*)malloc(sizeof(node));
    Head = StartList(Head);
    while(Selection!=5){
        Selection = Menu(Selection);
        switch (Selection){
            case 1:
               Head = AddBeginning(Head);
            break;

            case 2:
                AddBetween(PrevNode, NextNode);
            break;

            case 3:
                AppendEnd(PrevNode);
            break;

            case 4:
                ListPrinter(Head);
            break;

            case 5:
                printf("Have a nice day! See you soon!\n");
            break;
        }
    }
    return 0;
}

node* StartList(node* Head){
    printf("Please enter a value for the first element of the list: ");
    scanf("%d", &Head->m_nValue);
    Head->m_pNext = NULL;
    NodeCounter++;
    return Head;

}

node* AddBeginning (node* Head){
    int Value = 0;
    node* NewNode = (node*) malloc(sizeof(node));
    printf("Enter value for the next element: ");
    scanf("%d", &NewNode->m_nValue);
    NewNode->m_pNext = Head;
    Head = NewNode;
    NodeCounter++;
    return Head;
}

void AppendEnd (node* Head){
    int Value = 0;
    node* NewNode = (struct node*) malloc(sizeof(node));
    printf("Enter value for the next element: ");
    NewNode->m_nValue = scanf("%d", &Value);
    PrevNode->m_pNext = NewNode;
    NewNode->m_pNext = NULL;
}

void AddBetween(node* PrevNode, node* NextNode){
    int Value = 0;
    node* NewNode = (struct node*)malloc(sizeof(node));
    printf("Enter value for the next element: ");
    NewNode->m_nValue = scanf("%d", &Value);
    PrevNode->m_pNext = NewNode;
    NewNode->m_pNext = NextNode;
}

short Menu(short Selector){
    printf("Your list currently contsains %hd element(s).\n", NodeCounter);
    printf("What would you like to do next?\n");
    printf("1. Add element at the begining of the list.\n2. Add element after another element.\n3. Add element at the end of the list\n4.Print the list.\n5.Quit program.\nInput: ");
    selection:
    scanf("%hd", &Selector);
    if (Selector<1 || Selector>5){
        printf("Incorrect selection, please select a number between 1 and 5!");
        goto selection;
    }
    return Selector;
}

void ListPrinter(node* Head){
    node* PrintPoint = Head;
    printf("{");
    while(PrintPoint!=NULL){
        int i=0;
        printf("\tThe %dth element is: %d;\n", i++, PrintPoint->m_nValue);
        PrintPoint = PrintPoint->m_pNext;
    }
    printf("}\n");
}