#include <stdio.h>
#include "20210129_Task8_f.h"

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