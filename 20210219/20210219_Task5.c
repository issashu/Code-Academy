/*
Задача 5. 
    а) Направете поле 15 на 15, като принтирате тирета в конзолата. 
    b) Направете точка а(3, 4), като на това място принтирате @
    c) Направете точка b(7, 10), като на това място принтирате @
    d) Попълнете правоъгълника с @
*/

#include <stdio.h>
#include <stdlib.h>

const int X = 15; 
const int Y = 15; 

struct Coordinates{
    int x;
    int y;
};

void Setter(char Sign[X][Y]);
void Printer(char Sign[X][Y]);

int main(){
    char Graph[X][Y];
    struct Coordinates a = {3, 4};
    struct Coordinates b = {7, 10};
    void (*Board)(char[X][Y]) = Printer;

    Setter(Graph);

    printf("Podtochka a) :\n");
    Graph[a.x][a.y] = '@';
    Board(Graph);

    printf("Podtochka b) :\n");
    Graph[b.x][b.y] = '@';
    Board(Graph);

    printf("Podtochka c) :\n");
    for (int i=a.x; i<=b.x;i++){
        for(int j=a.y; j<=b.y; j++){
            Graph[i][j] = '@';
        }
    }
    Board(Graph);
}

void Setter(char Sign[X][Y]){
    for(int i=0; i<X; i++){
        for (int j=0; j<Y; j++){
            Sign[i][j]='-';    
        }
    }
}

void Printer(char Sign[X][Y]){
    for(int i=0; i<X; i++){
        for (int j =0; j<Y; j++){
            printf("%c", Sign[i][j]);    
        }
        printf("\n");
    }
}