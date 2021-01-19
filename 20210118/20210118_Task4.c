#include <stdio.h>

int main()
{
    int x=10;
    int y=10;
    int false =0;
    int true =1;

    //1. x<<1 = 20; 2. y&x = 0 ; 3. 20&&0 = 0
    true = x&&y&x<<1;
    
    //PRINTS 0
    printf("The expression \"true = x&&y&x<<1\" results in: %d\n", true);
    

    //1. x<<1 = 10100; 2.1010^10100 = 30 (11110); 3. 20&&30 = 1
    true = x&&y^x<<1;
    //PRINTS 1
    printf("The expression \"true = x&&y^x<<1\" results in: %d\n", true);


}