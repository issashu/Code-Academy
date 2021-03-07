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

#define min(x,y) (x) < (y) ? (x) : (y)

typedef struct{
    int8_t LongBoards;
    int8_t ShortBoards;
    int8_t LargeClamp;
    int8_t SmallClamp;
    int8_t Bolts;
} carpenter_t;

carpenter_t* CarpenterSetup(carpenter_t* Furniture, short Selector);
short CarpenterBuild(carpenter_t* Inventory, carpenter_t* Furniture, short Selector);

int main(){
    /* 0 is default inventory setup*/
    short Selector = 0;
    carpenter_t* Furniture = calloc(1, sizeof(carpenter_t));
    carpenter_t* Inventory = calloc(1, sizeof(carpenter_t));
    printf("Welcome to this automated carpenter unit XJ46!\n");
    printf("Today we can offer the following pieces of furniture:\n");
    printf("1.GODMORGON - bathroom cabinet\n2.RONNSKAR - shelf\n3.BEKANT - desk\n");
    printf("What do you need built today?\n");
    scanf("%hd", &Selector);

    Furniture = CarpenterSetup(Furniture, Selector);
    Inventory = CarpenterSetup(Inventory, 0);
    printf("The desired piece of furniture will require:\n%d Long Boards\n%d Short Boards\n%d Large Clamps\n%d Small Clamps\n%d Bolts\n", Furniture->LongBoards, Furniture->ShortBoards, Furniture->LargeClamp, Furniture->SmallClamp, Furniture->Bolts);
    printf("With the available materials we can assemble %hd furnitures of selected type\n", CarpenterBuild(Inventory, Furniture, Selector));
    free(Furniture);
    free(Inventory);
}

carpenter_t* CarpenterSetup (carpenter_t* Furniture, short Selector){
    switch (Selector){
        case 0:
            Furniture->LongBoards = 33;
            Furniture->ShortBoards = 55;
            Furniture->LargeClamp = 22;
            Furniture->SmallClamp = 88;
            Furniture->Bolts = 99; 
        break;

        case 1:
            Furniture->LongBoards = 20;
            Furniture->ShortBoards = 12;
            Furniture->LargeClamp = 5;
            Furniture->SmallClamp = 10;
            Furniture->Bolts = 32;
        break;

        case 2:
            Furniture->LongBoards = 4;
            Furniture->ShortBoards = 6;
            Furniture->LargeClamp = 2;
            Furniture->SmallClamp = 8;
            Furniture->Bolts = 10;
        break;

        case 3:
            Furniture->LongBoards = 10;
            Furniture->ShortBoards = 8;
            Furniture->LargeClamp = 4;
            Furniture->SmallClamp = 9;
            Furniture->Bolts = 110;
        break;
    }   
    return Furniture;
}

short CarpenterBuild(carpenter_t* Inventory, carpenter_t* Furniture, short Selector){
    short MaxBuild = 0;
    short MaxLB = Inventory->LongBoards/Furniture->LongBoards;
    short MaxSB = Inventory->ShortBoards/Furniture->ShortBoards;
    short MaxLC = Inventory->LargeClamp/Furniture->LargeClamp;
    short MaxSC = Inventory->SmallClamp/Furniture->SmallClamp;
    short MaxBt = Inventory->Bolts/Furniture->Bolts;

    /* <3 Excel function formatting ^^*/
    MaxBuild = min(MaxLB,min(MaxSB,min(MaxLC,min(MaxSC,MaxBt))));

    return MaxBuild;
}