#include <stdio.h>

int main() {
    int iValue = 47;
    int iDiv = 3;
    double dfRes = 0.0;
    dfRes = (double) (iValue / iDiv); 
    printf("Value of dfResof: %lf, V/D: %lf\n", dfRes, iValue/iDiv);

    dfRes = 47/3;
    
    return 0; 
}