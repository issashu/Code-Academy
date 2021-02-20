/*
Задача 6. Направете по подобен начин триъгълник:
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

    for (int i=a.x, j=a.y; i<=b.x, j<=b.y;i++, j++){
        Graph[i][j] = '@';
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
