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
    char string[32];
    int var1[32];
}key_t;

const enum keyword{
    k_auto = 0, 
    k_break, 
    k_case, 
    k_char, 
    k_const, 
    k_continue, 
    k_default, 
    k_do, 
    k_double, 
    k_else, 
    k_enum, 
    k_extern, 
    k_float, 
    k_for, 
    k_goto, 
    k_if, 
    k_int, 
    k_long,
    k_register, 
    k_return, 
    k_short, 
    k_signed, 
    k_sizeof, 
    k_static, 
    k_struct, 
    k_switch, 
    k_typedef, 
    k_union, 
    k_unsigned, 
    k_void, 
    k_volatile, 
    k_while,
};

void Setter(key_t *Struct);
void Printer (key_t *Struct);

int main(){
    key_t *Cwords = calloc(MaxKeyWords, sizeof(key_t));
    Setter(Cwords);
    Printer(Cwords);
}

void Setter(key_t *Struct){
    enum keyword Words;
    for (int i = 0; i<MaxKeyWords; i++){
        Struct->string[i] = Words +i;
        Struct->var1[i] = Words +i;
    }
}

void Printer (key_t *Struct){
    for (int i = 0; i<MaxKeyWords; i++){
        printf("%c", Struct->string[i]);
    }
}