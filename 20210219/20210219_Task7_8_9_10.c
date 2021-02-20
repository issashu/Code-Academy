/*
Използвам си кода от предишната задача, така че имената се различават, но са изпълнени изискванията. 
Голермината 15 е hard-coded в програмата

Задача 7. Направете функция struct point makepoint(int x, int y), която създава две точки.
Задача 8. Направете структура struct rect, която съдържа в себе си две точки. 
Създайте обект от тип тази структура наречен screen. Използвайте функцията makepoint за да зададете 
начална точка на екрана (0, 0) и крайна точка (15, 15). Запълнете пространството между тях с тирета.
Задача 9. Направете функця add(), която събира две точки. 
Задача 10. Направете два триъгълника с отместване.
*/
#include <stdio.h>
#include <stdlib.h>

const int MaxX = 15; 
const int MaxY = 15; 

typedef struct Coordinates{
    int x;
    int y;
} point;

point Setter();
void Printer(int m, int n, char Array[][n]);
void Add(point a, point b, point *combined);

int main(){
    int i;
    int j;
    point Intersection;
    char Screen[MaxX][MaxY];
    void (*Board)(int, int, char [MaxX][MaxY]) = Printer;

    //Задача 7 е тук:
    point RectStart = Setter();
    point RectEnd = Setter();
    
    for (i=RectStart.x; i<=RectEnd.x;i++){
        for(j=RectStart.y; j<=RectEnd.y; j++){
            Screen[i][j] = '-';
        }
    }
    //Задача 8 е тук:
    Board(i, j, Screen);

    //Задача 9 е тук:
    Add(RectStart, RectEnd, &Intersection);
    
}

struct Coordinates Setter(){
    //Задача 7 е тук:
    struct Coordinates Point;

    printf("Please enter coordinates x and y for the current point (Max X and Max Y are 15):\n");
    scanf("%d", &Point.x);
    scanf("%d", &Point.y);
    
    while(Point.y>15){
        printf("invalid X coordinate. Please enter a value less or equal 15:\n");
        scanf("%d", &Point.x);
    }

    while(Point.y>15){
        printf("invalid Y coordinate. Please enter a value less or equal 15:\n");
        scanf("%d", &Point.y);
    }

    return Point; 
}

void Printer(int m, int n, char Array[][n]){
    //Задача 8 е тук:
    int i;
    int j;

    for(i=0; i<=m; i++){
        for (j =0; j<=n; j++){
            printf("%c", Array[i][j]);    
        }
        printf("\n");
    }
}

void Add(point a, point b, point *combined){
    //Задача 9 е тук:
    combined->x = a.x+b.x;
    combined->y = a.y + b.y;

    printf("\n\nThe new point has coordinates: %d and %d", combined->x, combined->y);
}