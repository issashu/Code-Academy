/*
Задача 6. Напишете макрос с променлив брой параметри, който
извиква printf със префикс “TRACE: ”
*/
#include <stdio.h>

#define PRINTER(...) printf("TRACE: %s", __VA_ARGS__)

int main(){
    int x = 90;
    PRINTER("This is a string test!");
}


