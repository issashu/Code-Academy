/*
Напишете програма, която добавя и изтрива елемент от списъка по зададена стойност, която се пази в него. Използвайте следния елемент на двойно-свързания списък:
 
doubly linked list

typedef struct TDListNode { 
  int m_nValue; 
  struct TDListNode* m_pNextNode; 
  struct TDListNode* m_pPrevNode; 
} TDListNode;
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TDListNode { 
  int m_nValue; 
  struct TDListNode* m_pNextNode; 
  struct TDListNode* m_pPrevNode; 
} TDListNode;

int main()
{
	printf("Hello World!\n");

	return (0);
}