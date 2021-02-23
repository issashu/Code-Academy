/*
 Задача 8.
Напишете обединение от число и низ, както и описател с изброим тип за съдържанието 
на обединението. Напишете функция, която получава указател към обединението и изброимия 
тип и извежда съответно низ или число.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union MyUnion {
    uint32_t Var1;
    float Var2;
    char Var3[30];
};

enum ToPrint {
    Integer, 
    Floater, 
    Stringer
};

typedef struct Combined{
    union MyUnion UnionValue;
    enum ToPrint Selector;
}selection;

void UnionPrinter (selection* pEnumerate);

int main(){
    selection Enumerator;
    Enumerator.UnionValue.Var1=130;
    Enumerator.UnionValue.Var2 = 2.50;
    strcpy(Enumerator.UnionValue.Var3, "shokolad");
    
    selection *pEnum = &Enumerator;

    printf("Please select what you want to print:\n");
    printf("1. The integer; 2. The floater; 3. The stringer\n");
    scanf("%d", &Enumerator.Selector);
    UnionPrinter(pEnum);
}

void UnionPrinter (selection* pEnumerate){
    if (pEnumerate->Selector == 1){
        printf("%d", pEnumerate->UnionValue.Var1);
    }
    else if(pEnumerate->Selector == 2){
        printf("%.2f", pEnumerate->UnionValue.Var2);
    }
    else if(pEnumerate->Selector == 3){
        printf("%s", pEnumerate->UnionValue.Var3);
    }
}