#include <stdio.h> 

int main() 
{
    int nX = 33; /* homework, input with scanf */ 
    int nY = 20;

    printf("Please enter a value for the upcoming computations for nX and then nY: ");
    scanf ("%d", &nX);
    scanf ("%d", &nY);

    if (nX == nY) 
    {
        printf("%d and %d are equal\n", nX, nY);
    } else if (nX != nY)  // changed to include !=
        {
            printf("%d and %d are not equal\n", nX, nY);
        }

if (nX > nY) { printf("%d is greater than %d\n", nX, nY); }

if (nX < nY) { printf ("%d is less than %d\n", nX, nY); }

if (nX >= nY) { printf ("%d is at least equal to %d\n", nX, nY); }

if (nX <= nY) { printf ("%d is at maximum equal to %d\n", nX, nY); }
} /* използвайте и останалите оператори за сравнение */