/*
Задача 1. За да направи една етажерка, дърводелец се нуждае от следните компоненти: 4 дълги дъски, 
6 къси дъски, 12 малки скоби, 2 големи скоби и 14 винта. Дърводелецът има на склад А дълги дъски, В къси дъски, 
С малки скоби, D големи скоби и E винта. Колко етажерки може да направи дърводелецът?

Изход:
С наличните на склад материали (33 дълги дъски, 55 къси дъски, 88 малки скоби, 22 големи скоби и 99 винта) дърводелецът може да направи 7 етажерки.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
    int8_t LongBoards;
    int8_t ShortBoards;
    int8_t LargeClamp;
    int8_t SmallClamp;
    int8_t Bolts;
} carpenter_t;

carpenter_t* CarpenterBuild(carpenter_t* Furniture, char Flag);

int main(){
    char Selector = 'i';
    carpenter_t* Furniture = calloc(1, sizeof(carpenter_t));
    carpenter_t* Inventory = calloc(1, sizeof(carpenter_t));
    printf("Welcome to this automated carpenter uni XJ46!\n");
    printf("What do you need built today?");

    Furniture = CarpenterBuild(Furniture, 'f');
    Inventory = CarpenterBuild(Inventory, 'i');
    printf("The desired piece of furniture will require:\n%d Long Boards\n%d Short Boards\n%d Large Clamps\n%d Small Clamps\n%d Bolts\n", Furniture->LongBoards, Furniture->ShortBoards, Furniture->LargeClamp, Furniture->SmallClamp, Furniture->Bolts);
    printf("With the available materials we can assemble %d furnitures of selected type\n", Furniture->LongBoards/Inventory->LongBoards);
    free(Furniture);
    free(Inventory);
}

carpenter_t* CarpenterBuild (carpenter_t* Furniture, char Flag){
    if(Flag == 'i'){
        Furniture->LongBoards = 33;
        Furniture->ShortBoards = 55;
        Furniture->LargeClamp = 22;
        Furniture->SmallClamp = 88;
        Furniture->Bolts = 99;    
    }
    else{
        Furniture->LongBoards = 4;
        Furniture->ShortBoards = 6;
        Furniture->LargeClamp = 2;
        Furniture->SmallClamp = 12;
        Furniture->Bolts = 14;
    }
    
    return Furniture;
}