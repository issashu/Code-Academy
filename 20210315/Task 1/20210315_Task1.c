#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task1.h"

int main(){
    short Selection = 0;
    Head = (stek*)malloc(sizeof(stek));
    StartList(&Head);
    Tail = Head;
    while(Selection!=4){
        Selection = Menu(Selection);
        switch (Selection){
            case 1:
               Push(&Head);
            break;

            case 2:
                ListPrinter(Head);
            break;

            case 3:
                Pop(&Head);
            break;

            case 4:
                printf("Have a nice day! See you soon!\n");
            break;
        }
    }
    return 0;
}