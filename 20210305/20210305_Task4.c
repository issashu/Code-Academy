/* Да се състави програма, с помощта на която 2
(3, 1) играчи могат да играят (с право на връщане на
ходовете) следната игра ЛАБИРИНТ: Трябва да се достигне
до финала, отбелязан с F. Числото във всяка клетка
показва броя стъпки по права линия, които могат да са
направят при следващия ход. Като се започне от горния
ляв ъгъл, са възможни само два хода  */
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
    int counter;
}player;
#define ROWS 7
#define COLUMNS 7
#define F 70
short menu();
void game(player* A, int array[][COLUMNS]);
int main(void){
    int result;
    int array[ROWS][COLUMNS] =     {{3, 3, 2, 4, 3, 1, 2},
                                    {2, 4, 2, 3, 2, 4, 3},
                                    {4, 2, 3, 2, 4, 2, 1},
                                    {4, 4, 1, 2, 2, 3, 4},
                                    {3, 2, 3, 3, 4, 2, 2},
                                    {3, 2, 4, 2, 3, 2, 1},
                                    {1, 1, 3, 3, 4, 2, F}};

    player* A = (player*)malloc(sizeof(A));
    player* B = (player*)malloc(sizeof(A));
    printf("Player 1 started the game.\n");
    game(A, array);
    printf("Player 2 started the game.\n");
    game(B, array);

    
    
    
    free(A);
    free(B);
    return 0;
}
short menu(){
    short choice=0;
    printf("To move up press 1\nTo move left press 2\nTo move right press 3\nTo move down press 4\nTo rewind move press 5\n");
    scanf("%hd", &choice);
    return choice;
}
void game(player* A, int array[][COLUMNS]){
    int result = 0;
    A->x = 0;
    A->y = 0;
    A->counter = 0;
    int i=0, j =0;
    int backup_x = 0, backup_y=0;
    for(i=0 ; i < ROWS; i++){     
        for(j=0; j< COLUMNS; j++){       
            if(array[i][j] == F)
                printf("F");
            else
            printf("%d ", array[i][j]);       
        }
        printf("\n");
    }
    while(1){
        result = menu();
        printf("%d %d\n", backup_x, backup_y);
        switch(result){
            case 1:
            backup_x = A->x;
            backup_y = A->y;
            if(A->x - array[A->x][A->y] < 0)
                printf("Invalid move.\n");
            else
                A->x -= array[A->x][A->y];
            break;

            case 2:
            backup_x = A->x;
            backup_y = A->y;
            if(A->y - array[A->x][A->y] < 0)
                printf("Invalid move.\n");
            else
                A->y -= array[A->x][A->y];
            break;

            case 3:
            backup_x = A->x;
            backup_y = A->y;
            if(A->y + array[A->x][A->y] > 7)
                printf("Invalid move.\n");
            else
                A->y += array[A->x][A->y];
            break;

            case 4:
            backup_x = A->x;
            backup_y = A->y;
            if(A->x + array[A->x][A->y] > 7)
                printf("Invalid move.\n");
            else
                A->x += array[A->x][A->y];
            break;

            case 5:
                A->x = backup_x;
                A->y = backup_y;
                printf("%d %d\n", backup_x, backup_y);
            break;
        }

        A->counter++;
        if(array[A->x][A->y] == 70){
            printf("\nYou won the game with %d moves!\n", A->counter);
            break;
        }
        printf("You are on row [%d] position [%d] value: %d \n", A->x + 1, A->y + 1, array[A->x][A->y]);
        for(i=0 ; i < ROWS; i++){     
            for(j=0; j< COLUMNS; j++){
                if(A->x == i && A->y == j){
                    printf(".");
                }
                else if(array[i][j] == F)
                    printf("F");
                else
                    printf("%d ", array[i][j]);          
            }
            printf("\n");
        }

        

    }
}