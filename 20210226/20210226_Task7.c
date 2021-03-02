/*
Задача 7. Напишете масив от структури наречен kaytab[ ], като
използвате тази, дефинирана в горното упражнение - потребителски тип
key_t, която съдържа символен низ и число. Инициализирайте масива с
всички ключови думи на С.

https://www.programiz.com/c-programming/list-all-keywords-c-language

*/

#include <stdio.h>
#include <stdlib.h>

static const short MaxKeyWords = 32;

typedef struct{
    char string[20];
    int var1;
}key_t;

enum keyword = {auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto, if, int, long,	register, return, short, signed, sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while};

void Setter(key_t *Struct, enum List);

int main(){
    key_t *Cwords = calloc(32, sizeof(key_t));
    Setter(Cwords, MaxKeyWords);
}

void Setter(key_t *Struct, enum List){
    for (int i = 0; i<MaxKeyWords; i++){
        &Struct[i]->string = 
    }
}