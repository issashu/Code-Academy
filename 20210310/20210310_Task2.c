/*
Задача 2.
Напишете програма, която проверява дали всички отворени къдрави скоби {, (, [ за затворени ] ),},
Хвърлете грешка при липса на затварящи скоби и реда на който са.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *LineNr;
    bool *Flags;
    char Type;
} skoba;

int main(){
    skoba *Kadravi = calloc (5, sizeof(skoba));
    skoba *Kragli = calloc (5, sizeof(skoba));
    skoba *Kvadratni = calloc (5, sizeof(skoba));

}