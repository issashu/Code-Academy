/*
Задача 4. Да се изтрият в този ред върховете 1, 7, 12 и 
14 от дървото
*/
#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task4.h"

int main(){
    int ArrayOne[] = {6, 10, 5, 3, 8, 13, 1, 7, 11, 14, 12};
    int Delete[] = {1, 7, 12, 14};

    for (int i=0; i<11; i++){
        AddNode (&root, ArrayOne[i]);
    }

    for (int i=0; i<4; i++){
        RemoveNode(key, Delete[i]);
    }

}