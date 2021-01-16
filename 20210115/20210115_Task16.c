#include <stdio.h>

//gives a nice and fat warning, since it is external to the file
extern const float cPi=3.14159;

float Circle(float P, float R);

int main()
{
   float Radius=1.5;
   printf("%f\n", Circle(cPi, Radius));
   printf("%f\n", Circle(cPi, 1));
   printf("%f\n", Circle(cPi, 13));
}

float Circle(float P, float R)
{
    return P*R*R;
}