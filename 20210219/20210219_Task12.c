/*
Задача 12. Напишете функция, която изчислява разстоянието между две точки в равнината. 
Нека функцията да приема два параметъра, които са структури ТPoint с два члена X и Y координати.

https://www.calculatorsoup.com/calculators/geometry-plane/distance-two-points.php
*/

#include <stdio.h>
#include <math.h>

typedef struct TPoint{
    float x;
    float y;
} coordinate;

float KartDistance(coordinate one, coordinate two);

int main(){

    coordinate Point1;
    coordinate Point2;
    float Distance1to2;

    printf("Please enter the first point's coordinates:\n");
    scanf("%f", &Point1.x);
    scanf("%f", &Point1.y);

    printf("Please enter the second point's coordinates:\n");
    scanf("%f", &Point2.x);
    scanf("%f", &Point2.y);

    printf("Distance between the two points is:\n");
    Distance1to2 = KartDistance(Point1, Point2);
    printf("%.2f", Distance1to2);
}

float KartDistance(coordinate one, coordinate two){
    float Result = 0.00;

    float DifX = two.x - one.x;
    float DifY = two.y - one.y;

    Result = sqrt((DifX*DifX) + (DifY - DifY));

    return Result;
}