/*
Задача16:
Code designer: Iordan
Proofreading and optimization: Iordan & George;

1
Да се състави програма, с помощта на която играч може да
играе (с право на връщане на ходовете) следната игра СОЛИТЕР:
На игралното поле са поставени 16 номерирани пулове и три реда
с по осем позиции. Целта е да се извадят от игра всички пулове с
изключение на номер 1. Може да се прескача през някой пул на
свободна клетка, но не се разрешава движение по диагонал.
Например възможни са ходове 1-9; 2-10; 1-2 и т.н. По тази схема 1
прескача 9 и 9х излиза от игра – отстранява се от полето, след
това 2 прескача 10 и 10 отпада от играта; по-нататък 1 прескача 2 и
2 излиза от игра.


Task uses Parallel Array technique in a struct, which is there just for code convenience.
Can be done with 3 independent atrrays.
Using linear search to move through the arrays

Detailed rules of movement: https://sites.google.com/site/boardandpieces/list-of-games/checker-solitaire 

Music: http://code4k.blogspot.com/2010/05/playing-mp3-in-c-using-plain-windows.html

BUGS:
1. End-game condition missing
Optional: 2. Need to implement only 3 saves
Optional: 3. Need to add music
Optional: 4. Save to file
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int BoardSize = 8;
typedef struct{
    int Row1[8];
    int Row2[8];
    int Row3[8];
} gameboard;

/*Set flag y or n on variables*/
typedef struct{
    bool North;
    bool South;
    bool West;
    bool East;
    bool Row1;
    bool Row2;
    bool Row3;
} allowed;

gameboard* SetupGame(gameboard *Board);
void SaveGame(gameboard *MainBoard, gameboard *SaveBoard);
void LoadGame(gameboard *MainBoard, gameboard *SaveBoard);
int ValidateMovement(allowed *Directions, gameboard *MainBoard, int Piece, int Index);
char ContinueGame (char Continue);
void MovePiece(int Piece, char Direction, gameboard *MainBoard);
void PrintBoard(gameboard *MainBoard);

void Rules();
void Printer();

int main(){
    int Piece = '1';
    char Direction = 'n';
    char LoadVar = 'n';
    char Continue ='y';

    gameboard *MainBoard;
    gameboard *SaveBoard;
    MainBoard = SetupGame(MainBoard);
    SaveBoard = SetupGame(SaveBoard);

    Rules();
    /* Main Game Loop*/
    while(1){
        /*We save the state, in case the user wants to go back. After we execute commands for movement of the pieces.*/
        SaveGame(MainBoard, SaveBoard);
        PrintBoard(MainBoard);
        Printer();
        MovePiece(Piece, Direction, MainBoard);
        PrintBoard(MainBoard);
        printf("Do you need to turn back time? y/Y\n");
        scanf(" %c", &LoadVar);
        if(LoadVar == 'y' || LoadVar =='Y'){
            printf("The wind whispers \"Rinn-\" and the world shifts around you!\n\n");
            LoadGame(MainBoard, SaveBoard);
        }
        else{
            printf("Frodo moves ever so close to mount Doom:\n- Curse us and crush us, my precious is lost!\n\n");
        }
        Continue = ContinueGame(Continue);
        if(Continue=='n'|| Continue=='N'){
            free(MainBoard);
            free(SaveBoard);
            break;
        }
    }
}

int ValidateMovement(allowed *Directions, gameboard *MainBoard, int Piece, int Index){
    /*Locate the chose number as position in the arrays*/
    for (int i=0; i<BoardSize; i++){
        if(MainBoard->Row1[i] == Piece && (i>0&&i<BoardSize)){
            Directions->North = false;
            Directions->South = true;
            Directions->West = true;
            Directions ->East = true;
            Directions->Row1 = true;
            Directions->Row2 = false;
            Directions->Row3 = false;
            Index = i;
            break;
        }
        else if(MainBoard->Row1[i] == Piece && i==0){
            Directions->North = false;
            Directions->South = true;
            Directions->West = true;
            Directions ->East = false;
            Directions->Row1 = true;
            Directions->Row2 = false;
            Directions->Row3 = false;
            Index = i;
            break;
        }
        else if(MainBoard->Row1[i] == Piece && i==BoardSize){
            Directions->North = false;
            Directions->South = true;
            Directions->West = false;
            Directions ->East = true;
            Directions->Row1 = true;
            Directions->Row2 = false;
            Directions->Row3 = false;
            Index = i;
            break;
        }
        else if(MainBoard->Row2[i] == Piece && (i>0&&i<BoardSize)){
            Directions->North = false;
            Directions->South = false;
            Directions->West = true;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = true;
            Directions->Row3 = false;
            Index = i;
            break;
        }
        else if(MainBoard->Row2[i] == Piece && i==0){
            Directions->North = false;
            Directions->South = false;
            Directions->West = true;
            Directions ->East = false;
            Directions->Row1 = false;
            Directions->Row2 = true;
            Directions->Row3 = false;
            Index = i;
            break;
        }
        else if(MainBoard->Row2[i] == Piece && i==BoardSize){
            Directions->North = false;
            Directions->South = false;
            Directions->West = false;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = true;
            Directions->Row3 = false;
            Index = i;
            break;
        }
        else if(MainBoard->Row3[i] == Piece && (i>0&&i<BoardSize)){
            Directions->North = true;
            Directions->South = false;
            Directions->West = true;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = false;
            Directions->Row3 = true;
            Index = i;
            break;
        }
        else if(MainBoard->Row3[i] == Piece && i==0){
            Directions->North = true;
            Directions->South = false;
            Directions->West = true;
            Directions ->East = false;
            Directions->Row1 = false;
            Directions->Row2 = false;
            Directions->Row3 = true;
            Index = i;
            break;
        }
        else if(MainBoard->Row3[i] == Piece && i==BoardSize){
            Directions->North = true;
            Directions->South = false;
            Directions->West = false;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = false;
            Directions->Row3 = true;
            Index = i;
            break;
        }
    }
    /*DEBUG:
    printf("Allowed moves\nN:%d S:%d E:%d W:%d\n", Directions->North, Directions->South, Directions->East, Directions->West); 
    printf("Allowed Rows: Row1:%d Row2:%d Row3:%d\n", Directions->Row1, Directions->Row2, Directions->Row3);
   */
    return Index;
}

void MovePiece(int Piece, char Direction, gameboard *MainBoard){
    //char PieceMoved = '1';
    int Index = 0;
    allowed *AllowedMovement = calloc(1, sizeof(allowed));
    scanf(" %d", &Piece);
    scanf(" %c", &Direction);
    Index = ValidateMovement(AllowedMovement, MainBoard, Piece, Index);
    
    //add directon small caps only
    //validate that second row can not be moved
    switch(Direction){
        case 'n':
        if (AllowedMovement->North==true){
            if(MainBoard->Row1[Index]=='-'){
                MainBoard->Row1[Index] = MainBoard->Row3[Index];
                MainBoard->Row3[Index] = '-';
                MainBoard->Row2[Index] = '-';
            }
            else{
                printf("Illegal move selected! You can hop only over a non-empty position and land on an empty one!\n\n");
            }
        }
        break;

        case 's':
        if (AllowedMovement->South==true){
            if(MainBoard->Row3[Index]=='-'){
                MainBoard->Row3[Index] = MainBoard->Row1[Index];
                MainBoard->Row1[Index] = '-';
                MainBoard->Row2[Index] = '-';
            }
            else{
                printf("Illegal move selected! You can hop only over a non-empty position and land on an empty one!");
            }
        }
        break;

        case 'e':
        if (AllowedMovement->East==true && AllowedMovement->Row1==true){
            if(MainBoard->Row1[Index-2]=='-'){
                MainBoard->Row1[Index-2] = MainBoard->Row1[Index];
                MainBoard->Row1[Index] = '-';
                MainBoard->Row1[Index-1] = '-';
            }
        }
        else if (AllowedMovement->East==true && AllowedMovement->Row3==true){
            if(MainBoard->Row3[Index-2]=='-'){
                MainBoard->Row3[Index-2] = MainBoard->Row3[Index];
                MainBoard->Row3[Index] = '-';
                MainBoard->Row3[Index-1] = '-';
            }
        }
        else if (AllowedMovement->East==true && AllowedMovement->Row2==true){
            if(MainBoard->Row2[Index-2]=='-'){
                MainBoard->Row2[Index-2] = MainBoard->Row2[Index];
                MainBoard->Row2[Index] = '-';
                MainBoard->Row2[Index-1] = '-';
                }
            }   
        else{
            printf("Illegal move selected! You can hop only over a non-empty position and land on an empty one!");
        }
        break;

        case 'w':
        if (AllowedMovement->West==true && AllowedMovement->Row1==true){
            if(MainBoard->Row1[Index+2]=='-'){
                MainBoard->Row1[Index+2] = MainBoard->Row1[Index];
                MainBoard->Row1[Index] = '-';
                MainBoard->Row1[Index+1] = '-';
            }
        }
        else if (AllowedMovement->West==true && AllowedMovement->Row3==true){
            if(MainBoard->Row3[Index+2]=='-'){
                MainBoard->Row3[Index+2] = MainBoard->Row3[Index];
                MainBoard->Row3[Index] = '-';
                MainBoard->Row3[Index+1] = '-';
            }
        }
        else if (AllowedMovement->West==true && AllowedMovement->Row2==true){
            if(MainBoard->Row2[Index+2]=='-'){
                MainBoard->Row2[Index+2] = MainBoard->Row2[Index];
                MainBoard->Row2[Index] = '-';
                MainBoard->Row2[Index+1] = '-';
            }
            else{
                printf("Illegal move selected! You can hop only over a non-empty position and land on an empty one!");
            }
        break;
        }   
    }
    free(AllowedMovement);
}
    

void SaveGame(gameboard *MainBoard, gameboard *SaveBoard){
    for(int i=0;i<BoardSize;i++){
        SaveBoard->Row1[i] = MainBoard->Row1[i];
        SaveBoard->Row2[i] = MainBoard->Row2[i];
        SaveBoard->Row3[i] = MainBoard->Row3[i];
    }
}

void LoadGame(gameboard *MainBoard, gameboard *SaveBoard){
    for (int i=0; i<BoardSize; i++){
        MainBoard->Row1[i] = SaveBoard->Row1[i];
        MainBoard->Row2[i] = SaveBoard->Row2[i];
        MainBoard->Row3[i] = SaveBoard->Row3[i];
    }
    
}

gameboard* SetupGame(gameboard *Board){
    /*Creates a game board and returns pointer to it*/
    Board = calloc(3, sizeof(gameboard));

    for(int i=0; i<BoardSize; i++){
        Board->Row1[i] =   45;
        Board->Row2[i] =  9+i;
        Board->Row3[i] =  1+i;
    }
    return Board;
}

void Rules(){
    printf("Welcome to LoTR - Console Adventures! The rules of the game are simple:\n");
    printf("-You need to help Frodo reach mount doom with the one ring.\n-He can defeat Saruman's orcs by jumping over them.\n");
    printf("-He can jump over an orc only if there is a free spot on the other side (aka a dash sign  -)\n");
    printf("-Frodo can jump one position vertically between the three paths or horizontally on the same path.\n");
    printf("-Frodo's friends can help him by displacing enemy forces, following the same movement rules as himself, so that Frodo can take them by surprise.\n");
    printf("-And don't forget: Frodo can use the one ring to turn back time to his previous move, but only three times!\n\n\n");
    printf("o=|==============>   One ring to rule them all and into darkness bind them   <==============|=o\n\n\n");

    printf("Press \"any key\" to continue:");
    getchar();

    /* Using print raw string literall printf (R"()") is a c11 feature*/
    printf(R"(
                       \ : /
                    '-: __ :-'
                    -:  )(_ :--
                    -' |r-_i'-
            ,sSSSSs,   (2-,7
            sS';:'`Ss   )-j
           ;K e (e s7  /  (
            S, ''  SJ (  ;/
            sL_~~_;(S_)  _7
|,          'J)_.-' />'-' `Z
j J         /-;-A'-'|'--'-j\
 L L        )  |/   :    /  \
  \ \       | | |    '._.'|  L
   \ \      | | |       | \  J
    \ \    _/ | |       |  ',|
     \ L.,' | | |       |   |/
    _;-r-<_.| \=\    __.;  _/
      {_}"  L-'  '--'   / /|
            |   ,      |  \|
            |   |      |   ")
            L   ;|     |   /|
           /|    ;     |  / |
          | |    ;     |  ) |
         |  |    ;|    | /  |
         | ;|    ||    | |  |
         L-'|____||    )/   |
             % %/ '-,- /    /
     snd     |% |   \%/_    |
          ___%  (   )% |'-; |
        C;.---..'   >%,(   "'
                   /%% /
                  Cccc')");

    printf("\n\n\n");
}

void Printer(){
    printf("Who do you want to move (Frodo - figure 1 or any enemy - other numbers?\n");
    printf("Do hurry! The Nine have left Minas Morgul!\n");
    printf("Choose one number and then a direction in lowercase. Allowed directions: n/s/e/w\n");
}

void PrintBoard(gameboard *MainBoard){
    for (int i=0; i<BoardSize; i++){
        if(MainBoard->Row1[i] == 45){
            printf("%2c\t", MainBoard->Row1[i]);    
        }
        else{
            printf("%2d\t", MainBoard->Row1[i]);
        }
    }
    printf("\n");

    for (int i=0; i<BoardSize; i++){
        if(MainBoard->Row2[i] == 45){
            printf("%2c\t", MainBoard->Row2[i]);    
        }
        else{
            printf("%2d\t", MainBoard->Row2[i]);
        }
    }
    printf("\n");

    for (int i=0; i<BoardSize; i++){
        if(MainBoard->Row3[i] == 45){
            printf("%2c\t", MainBoard->Row3[i]);    
        }
        else{
            printf("%2d\t", MainBoard->Row3[i]);
        }
    }
    printf("\n");
}

char ContinueGame (char Continue){
    
    CONTINUE: 
    printf("Frodo wouldn't have got far without Sam, would he, dad? (Continue: y/n)\n");
    scanf(" %c", &Continue);
    
    if (Continue == 'y' || Continue =='Y'){
        printf("Now, Mr. Frodo, you shouldn't make fun. I was serious.\n");
        return Continue;
    }
    else if(Continue == 'n' || Continue =='N'){
        printf("Farewell, King under the Mountain! This is a bitter adventure, if it must end so!\n");
        return Continue;
    }
    else{
        goto CONTINUE;
    }
}