/*
Задача 1. Дефинирайте структура като
потребителски тип. Инициализирайте членовете на
структурата, използвайки новия потребителски тип.
Отпечатайте.
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char string[80];
    int var1;
}key_t;

int main(){
    key_t PassKey;

    strcpy(PassKey.string,"It is what you get after you remove from the Spartan defense a hundred");
    PassKey.var1 = 200;
    printf("%s\n", PassKey.string);
    printf("%d", PassKey.var1);

}