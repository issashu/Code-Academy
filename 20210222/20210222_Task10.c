/*
 Задача 10.
Използвайки горните две задачи като база, обединете обединението и описателя в една структура. 
Напишете функция, която извежда съдържанието на новата структура.

Миии то аз ги правих смесени в предишните две, така че просто копирам 9та задача и тук.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union MyUnion {
    uint32_t Var1;
    char Var3[30];
};

enum ToPrint {
    Integer, 
    Stringer
};

typedef struct Combined{
    union MyUnion UnionValue;
    enum ToPrint Selector;
}selection;

void UnionPrinter (selection* pEnumerate, int Number);

int main(){
    selection Data;
    int Number = 0;

    selection *pEnum = &Data;
    printf("What is the number to be stored/printed?\n");
    scanf("%d", &Number);
    printf("Do you need then value stored (press 1) or printed (press 2)?\n");
    scanf("%d", &pEnum->Selector);

    UnionPrinter(pEnum, Number);
}

void UnionPrinter (selection* pEnumerate, int Number){
    if (pEnumerate->Selector == 1){
        pEnumerate->UnionValue.Var1 = Number;
        printf("Value stored is: %d\n", pEnumerate->UnionValue.Var1);
    }
    else if(pEnumerate->Selector == 2){
        snprintf(pEnumerate->UnionValue.Var3, 30, "%d", Number);
        printf("Value in printing is: %s\n", pEnumerate->UnionValue.Var3);
    }
}