/*
Задача 7. Напишете програма на С, която съдържа 2 функции. 
1.Първата смята лице на правоъгълен триъгълник.
2.Втората използва лицето на триъгълника, за да сметне лице на четириъгълник 
със същите дължини на страните, като раменете на триъгълника.  
Напишете прототипите на функциите най-отгоре, а телата им под мейн функцията.
*/

#include <stdio.h>

double TriangleArea (double a, double b);
double SquareArea (double triangle);

int main(){
    double a = 0.00;
    double b = 0.00;

    printf("Please insert the lenght of the two sides of a triagnle:\n");
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf("The triangle area with the entered lenghts is: %lf\n", TriangleArea(a, b));
    printf("The triangle area with the entered lenghts is: %lf\n", SquareArea(TriangleArea(a, b)));
}

double TriangleArea (double a, double b){
    double Area = 0.00;

    Area = (a*b)/2;
    return Area;
}

double SquareArea (double triangle){
    double Area = 0.00;

    Area = triangle + triangle;
    return  Area;
}