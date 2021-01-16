#include <stdio.h>

//gives a nice and fat warning, since it is external to the file
extern const float cPi=3.14159;

float Circle(float P, float R);
float Elipse (float P, float A, float B);

int main()
{
   //Circle
   float Radius=1.5;
   printf("%.2f\n", Circle(cPi, Radius));
   printf("%.2f\n", Circle(cPi, 1));
   printf("%.2f\n", Circle(cPi, 13));

   //Elipse - can get A and B declared as variables instead
   printf("%.2f", Elipse(cPi, 1.3, 2.4));

}

float Circle(float Pi, float R)
{
    return Pi*R*R;
}

float Elipse (float Pi, float A, float B)
{
    return Pi*A*B;
}