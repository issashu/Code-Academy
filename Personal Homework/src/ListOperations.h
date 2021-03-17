#ifndef LISTOPERATIONS_H
#define LISTOPERATIONS_H

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

#endif /*LISTOPERATIONS_H*/