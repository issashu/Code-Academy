/*
Задача 19. Дефинирайте стринг: „Baba, kaka, mama” заменете „а“ със „о“
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char array[] = "Baba, Kaka, Mama";
    char *Pointy = &array[0];

    while(*Pointy){
        if(*Pointy == 'a'){
            *Pointy = 'o';
        }
        *Pointy++;
    }

    printf("%s", array);
}
