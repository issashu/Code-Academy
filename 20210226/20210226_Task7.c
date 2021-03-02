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

typedef enum keyword {
    auto = 0, 
    break, 
    case, 
    char, 
    const, 
    continue, 
    default, 
    do, 
    double, 
    else, 
    enum, 
    extern, 
    float, 
    for, 
    goto, 
    if, 
    int, 
    long,
    register, 
    return, 
    short, 
    signed, 
    sizeof, 
    static, 
    struct, 
    switch, 
    typedef, 
    union, 
    unsigned, 
    void, 
    volatile, 
    while} word;

void Setter(key_t *Struct);
void Printer (key_t *Struct);

int main(){
    key_t *Cwords = calloc(32, sizeof(key_t));
    Setter(Cwords);
    Printer(Cwords);
}

void Setter(key_t *Struct){
    for (int i = 0; i<MaxKeyWords; i++){
        word = i;
        Struct->string[i] = word;
        Struct->var1[i] = word;
    }
}

void Printer (key_t *Struct){
    for (int i = 0; i<MaxKeyWords; i++){
        printf("%c", Struct->string[i]);
    }
}