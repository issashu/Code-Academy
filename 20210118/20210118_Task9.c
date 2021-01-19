#include <stdio.h> 

int main()
{
    //given example
    int iX = 13;
    int iY = 44;
    int iResult = 0;
    iResult = iX - iY;
    printf("%d - %d = %d \n", iX, iY, iResult);
    iResult = iY / iX;
    printf("%d / %d = %d \n", iY, iX, iResult);
    iResult = iY % iX;
    printf("%d / %d Remainder: %d\n", iY, iX, iResult);

    /* homework: examples for '*' и '+', float - използвайте вместо int*/

    float fX = 12.34;
    float fY = 6.66;
    float fResult = 0.00;

    fResult = (fX * fY);
    printf("%.2f * %.2f = %.2f \n", fX, fY, fResult);

    fResult = (fX + fY);
    printf("%.2f + %.2f = %.2f \n", fX, fY, fResult);

    return 0;
}