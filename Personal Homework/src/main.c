#include <stdio.h>
#include <stdlib.h>
#include "ListOperations.h"

int main(){
    short Selection = 0;
    Head = (TDListNode*)malloc(sizeof(TDListNode));
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

