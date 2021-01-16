#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Numbers[4];
    for (int i=0; i<4; i++) 
        Numbers[i]=0xAA;
    
    /* DEBUG: Each element takes 4 bytes in memory
    for (int i=0; i<4; i++)
        printf("Address of Numbers[%d] is: %p\n", i, &Numbers[i]);
    */

    for (int i=0; i<4; i++)
        printf("Element Numbers [%d] and type is float: %.2f\n", i, (float) Numbers[i]);
    
    for (int i=0; i<4; i++)
        printf("Element Numbers [%d] and type is int: %d\n", i, Numbers[i]);

    for (int i=0; i<4; i++)
        printf("Element Numbers [%d] and type is unsigned int: %u\n", i, Numbers[i]);
}