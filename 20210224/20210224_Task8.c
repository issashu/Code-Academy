/*
Задача 8. Напишете макрос, който свързва два идентификатора в
един общ (конкатениране на идентификатори)
*/
#include <stdio.h>

#define COMMAND(NAME, MAME) NAME ## MAME 

int main(){
COMMAND (print, f) ("I did not understand a thing about macros!!! Homework is done the parrot way!!");
}