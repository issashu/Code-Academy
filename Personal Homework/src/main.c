/*Character navigates back and forth a train to solve a mystery. Waggons are linked in a doubly linked list
for the purpose of the exercise*/
#include <stdio.h>
#include <stdlib.h>
#include "ListOperations.h"

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
                RemoveNode(Head, Tail);
            break;

            case 6:
                printf("Have a nice day! See you soon!\n");
            break;
        }
    }
    return 0;
}

