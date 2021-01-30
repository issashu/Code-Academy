/*
Задача 2. Напишете функция area() без параметри. 
Поискайте от потребителя да въведе радиуса с помощта на функциите :
printf("Enter a radius\n");
scanf("%lf", &r);
Използвайте горната функция 1.за изчисляване на площта на кръг,
която написахме преди малко за да изчислите площта на кръга с този радиус 
и върнете резултата.
*/

#include <stdio.h>

const float cPi = 3.14;

double Circle(double radius);
double Area();
void Debug (float cPi, double radius);

int main()
{
    double CircleRad = Circle(Area());
    printf("%.2f\n", CircleRad);
    /*DEBUFG:
    Debug(cPi,  CircleRad);*/
    
}

double Area(){
    double r=0.00;
    printf("Hell traveler to our little Inn. Please enter a radius for thy plate:\n");
    scanf ("%lf", &r);
    return r;
}
double Circle (double radius){
    return cPi*radius*radius;
}

void Debug (float cPi, double radius){
    printf("r = : %lf\n", radius);
    printf("%f * %lf * %lf\n", cPi, radius, radius);
}