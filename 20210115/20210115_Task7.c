#include <stdio.h>
#include <stdlib.h>

int main()
{
    double Numbers[4];
    for (int i=0; i<4; i++) 
        Numbers[i]=0xBB;
    
    /* DEBUG: Each element takes 8 bytes in memory
    for (int i=0; i<4; i++)
        printf("Address of Numbers[%d] is: %p\n", i, &Numbers[i]);
    */

    for (int i=0; i<4; i++)
        printf("Element Numbers [%d] and type is float: %.2lf\n", i, Numbers[i]);
    
    for (int i=0; i<4; i++)
        printf("Element Numbers [%d] and type is long double: %Ld\n", i, Numbers[i]);

    for (int i=0; i<4; i++)
        printf("Element Numbers [%d] and type is unsigned long double: %LLd\n", i, Numbers[i]);
}