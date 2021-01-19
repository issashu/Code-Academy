#include <stdio.h> 

int main()
{
    int nA = 1;
    int nB = 1; 
    printf("Enter value for nA: ");
    scanf("%d", &nA);
    printf("A value is %d\n", nA);
    nB = ( nA == 1 ? 2 : 0 ); 
    printf("B value is %d\n", nB);

    (nA > nB ? printf("nA is the bigger number") : printf("nB is the bigger number"));

    
}