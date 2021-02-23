/*
 Задача 7.
Напишете обединение от три стойности: цяло число, число с плаваща запетая и низ. 
Инициализирайте отделните членове и ги изведете на екрана.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

union MyUnion {
    uint16_t Var1;
    float Var2;
    char Var3[30];
};

int main(){
    union MyUnion Test1 = {.Var1 = 1};
    union MyUnion Test2 = {.Var2 = 10.75};
    union MyUnion Test3 = {.Var3 = "Yes, this is dog!"};

    printf("%d , %.2f, %s ", Test1.Var1, Test1.Var2, Test3.Var3);
}