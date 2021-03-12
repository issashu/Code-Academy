/*
Задача 1. Реализация на списък. Напишете програма, която добавя и 
изтрива елемент от списък по позиция в списъка. Използвайте следния 
елемент на динамичния списък:
typedef struct t_node { 
int m_nValue; 
t_node* m_pNext; 
} t_node; 
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct t_node { 
    u_int Index;
    int m_nValue; 
    t_node* m_pNext; 
} t_node; 

void AddListElement (t_node* PrevNode);

int main(){
    struct t_node* head = NULL;  
    head = (struct t_node*)malloc(sizeof(t_node)); 
    head->m_nValue = 1;
    head->Index = 0;
    head->m_pNext = NULL;

    AddListElement(head);
}

void AppendElement (t_node* PrevNode){
    int Value = 0;
    t_node* NewNode = (struct t_node*)malloc(sizeof(t_node));
    printf("Enter value for the next element: ");
    NewNode->m_nValue = scanf("%d", &Value);
    PrevNode->m_pNext = NewNode;
    NewNode->Index = PrevNode->Index+1;
    NewNode->m_pNext = NULL;
}

void AddBetween(t_node* PrevNode, t_node* NextNode){
    int Value = 0;
    t_node* NewNode = (struct t_node*)malloc(sizeof(t_node));
    printf("Enter value for the next element: ");
    NewNode->m_nValue = scanf("%d", &Value);
    PrevNode->m_pNext = NewNode;
    NewNode->Index = PrevNode->Index+1;
    NewNode->m_pNext = NextNode;
}