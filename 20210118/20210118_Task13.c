#include <stdio.h> 

int main() 
{
    int nA = 40; /* използвайте scanf */ 
    int nB = 20;
    int nX = 20;
    int nY = 30;

    printf("Please enter 4 values separated by enter key for the variables nA, nB, nX and nY:\n");
    scanf("%d", &nA);
    scanf("%d", &nB);
    scanf("%d", &nX);
    scanf("%d", &nY);


    if ( nA > nB && nA !=0 ) 
    {
        printf("&& Operator : Both conditions are true\n");
    }
    if ( nX > nY || nY != 20) 
    {
        printf("|| Operator : Art least one of the two conditions is true\n");
    }
    if ( ! (nA > nB && nB !=0 ) ) 
    {
        printf(" ! Operator on (nA > nB && nB !=0 ) : At least one of the conditions was false\n"); 
    } else 
        {
            printf("! Operator on (nA > nB && nB !=0 ) : Both conditions were true.\n");
        }
    
    if (nA>>1 != nY <<1) {printf ("After shifting nA and nY, they were not equal");}

    if (nA<<1 <= (nY&nX)>>1) {printf ("nA shifted once left is less or equal to combined AND of nX and nY shifted rifght once");}
}