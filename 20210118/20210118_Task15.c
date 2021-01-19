#include <stdio.h> 

int main()
{
    int nA = 1;
    int nB = ( nA == 1 ? 2 : 0 );

    printf("Please enter a value for nA: ");
    scanf("%d", &nA);
    
    /*
    printf("Please enter a value for nB: ");
    scanf("%d", &nB); 
    */
    
    printf("A value is %d\n", nA); 
    printf("B value is %d\n", nB); 

    (nA > nB ? printf("A is bigger") : printf("B is bigger"));

}