#include <stdio.h>

const float cPi = 3.14;

float Circle(float radius);
float Menu();

int main()
{
    printf("%.2f", Circle(Menu()));
    
}

float Menu(){
    float Radius=0.00;
    printf("Hell traveler to our little Inn. Please enter a radius for thy plate:\n");
    scanf ("%f", &Radius);

    return Radius;
}

float Circle (float radius){
    return cPi*radius*radius;
}