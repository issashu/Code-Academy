/*Task uses Parallel Array technique in a struct, which is there just for code convenience.
Can be done with 3 independent atrrays.
Using linear search to move through the arrays

Detailed rules of movement: https://sites.google.com/site/boardandpieces/list-of-games/checker-solitaire 

BUGS:
1. End-game condition missing
2. Save and load game pointers are equal
3. Need to implement only 3 saves
Optional: 4. Need to add music
Optional: 5. Save to file
6. Index is bugged in Move function
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int BoardSize = 8;
typedef struct{
    char Row1[8];
    char Row2[8];
    char Row3[8];
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
gameboard* SaveGame(gameboard *MainBoard, gameboard *SaveBoard);
gameboard* LoadGame(gameboard *MainBoard, gameboard *SaveBoard);
int ValidateMovement(allowed *Directions, gameboard *MainBoard, char Piece);
char ContinueGame (char Continue);
void MovePiece(char Piece, char Direction, gameboard *MainBoard);
void PrintBoard(gameboard *MainBoard);

void Rules();
void Printer();

int main(){
    char Piece = '1';
    char Direction = 'N';
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
        SaveBoard = SaveGame(MainBoard, SaveBoard);
        PrintBoard(MainBoard);
        Printer();
        MovePiece(Piece, Direction, MainBoard);
        PrintBoard(MainBoard);
        printf("Do you need to turn back time? y/Y\n");
        scanf(" %c", &LoadVar);
        if(LoadVar == 'y' || LoadVar =='Y'){
            printf("The wind whispers \"Rinn-\" and the world shifts around you!\n\n");
            MainBoard = LoadGame(MainBoard, SaveBoard);
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

int ValidateMovement(allowed *Directions, gameboard *MainBoard, char Piece){
    /*Locate the chose number as position in the arrays*/
    int i = 0;
    for (int i=0; i<BoardSize; i++){
        if(MainBoard->Row1[i] == Piece && (i>0&&i<BoardSize)){
            Directions->North = false;
            Directions->South = true;
            Directions->West = true;
            Directions ->East = true;
            Directions->Row1 = true;
            Directions->Row2 = false;
            Directions->Row3 = false;
        }
        else if(MainBoard->Row1[i] == Piece && i==0){
            Directions->North = false;
            Directions->South = true;
            Directions->West = true;
            Directions ->East = false;
            Directions->Row1 = true;
            Directions->Row2 = false;
            Directions->Row3 = false;
        }
        else if(MainBoard->Row1[i] == Piece && i==BoardSize){
            Directions->North = false;
            Directions->South = true;
            Directions->West = false;
            Directions ->East = true;
            Directions->Row1 = true;
            Directions->Row2 = false;
            Directions->Row3 = false;
        }
        else if(MainBoard->Row2[i] == Piece && (i>0&&i<BoardSize)){
            Directions->North = true;
            Directions->South = true;
            Directions->West = true;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = true;
            Directions->Row3 = false;
        }
        else if(MainBoard->Row2[i] == Piece && i==0){
            Directions->North = true;
            Directions->South = true;
            Directions->West = true;
            Directions ->East = false;
            Directions->Row1 = false;
            Directions->Row2 = true;
            Directions->Row3 = false;
        }
        else if(MainBoard->Row2[i] == Piece && i==BoardSize){
            Directions->North = true;
            Directions->South = true;
            Directions->West = false;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = true;
            Directions->Row3 = false;
        }
        else if(MainBoard->Row3[i] == Piece && (i>0&&i<BoardSize)){
            Directions->North = true;
            Directions->South = false;
            Directions->West = true;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = false;
            Directions->Row3 = true;
        }
        else if(MainBoard->Row3[i] == Piece && i==0){
            Directions->North = true;
            Directions->South = false;
            Directions->West = true;
            Directions ->East = false;
            Directions->Row1 = false;
            Directions->Row2 = false;
            Directions->Row3 = true;
        }
        else if(MainBoard->Row3[i] == Piece && i==BoardSize){
            Directions->North = true;
            Directions->South = false;
            Directions->West = false;
            Directions ->East = true;
            Directions->Row1 = false;
            Directions->Row2 = false;
            Directions->Row3 = true;
        }
    }
    /*DEBUG: */
    printf("Allowed moves\nN:%d S:%d E:%d W:%d\n", Directions->North, Directions->South, Directions->East, Directions->West); 
    printf("Allowed Rows: Row1:%d Row2:%d Row3:%d\n", Directions->Row1, Directions->Row2, Directions->Row3);
   
    return i;
}

void MovePiece(char Piece, char Direction, gameboard *MainBoard){
    char PieceMoved = '1';
    int Index = 0;
    allowed *AllowedMovement = calloc(1, sizeof(allowed));
    scanf(" %c", &Piece);
    scanf(" %c", &Direction);
    Index = ValidateMovement(AllowedMovement, MainBoard, Piece);
    
    //add directon small caps only
    //validate that second row can not be moved
    switch(Direction){
        case 'n':
        if (AllowedMovement->North==true){
            if(MainBoard->Row1[Index]=='-'){
                MainBoard->Row1[Index] = MainBoard->Row3[Index];
                MainBoard->Row3[Index] = '-';
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
            }
        }
        else if (AllowedMovement->East==true && AllowedMovement->Row3==true){
            if(MainBoard->Row3[Index-2]=='-'){
                MainBoard->Row3[Index-2] = MainBoard->Row3[Index];
                MainBoard->Row3[Index] = '-';
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
            }
        }
        else if (AllowedMovement->West==true && AllowedMovement->Row3==true){
            if(MainBoard->Row3[Index+2]=='-'){
                MainBoard->Row3[Index+2] = MainBoard->Row3[Index];
                MainBoard->Row3[Index] = '-';
            }
        }
        else{
            printf("Illegal move selected! You can hop only over a non-empty position and land on an empty one!");
        }
        break;
    }
    free(AllowedMovement);
}
    

gameboard* SaveGame(gameboard *MainBoard, gameboard *SaveBoard){
    SaveBoard = MainBoard;
    return SaveBoard;
}

gameboard* LoadGame(gameboard *MainBoard, gameboard *SaveBoard){
    MainBoard = SaveBoard;
    return MainBoard;
}

gameboard* SetupGame(gameboard *Board){
    /*Creates a game board and returns pointer to it*/
    Board = calloc(3, sizeof(gameboard));

    for(int i=0; i<BoardSize; i++){
        Board->Row1[i] = '-';
        Board->Row2[i] = 9+i;
        Board->Row3[i] = 49+i;
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
    printf("Choose one number and thern a direction (N/S/E/W)\n");
}

void PrintBoard(gameboard *MainBoard){
    for (int i=0; i<BoardSize; i++){
        printf("%2c\t", MainBoard->Row1[i]);
    }
    printf("\n");

    for (int i=0; i<BoardSize; i++){
        printf("%2d\t", MainBoard->Row2[i]);
    }
    printf("\n");

    for (int i=0; i<BoardSize; i++){
        printf("%2c\t", MainBoard->Row3[i]);
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