#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char Row1[8];
    char Row2[8];
    char Row3[8];
} gameboard;

void MovePiece();
void SaveGame();
void SetupGame(gameboard *Board);
void Printer();

int main(){
    gameboard *MainBoard;
    gameboard *SaveBoard;
    MainBoard = SetupGame(MainBoard);
    SaveBoard = SetupGame();

    /* Main Game Loop*/
    while(1){


    }
}

void MovePiece(){

}

void SaveGame(){

}

gameboard* SetupGame(gameboard *Board){
    /*Creates a game board and returns pointer to it*/
    Board = calloc(3, sizeof(gameboard));

    return Board;
}

void Printer(){

}