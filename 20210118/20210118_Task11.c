#include <stdio.h> 

int main() 
{
    int iCounter = 0;
    while( ++ iCounter < 3 )   // Increments to 1 and then checks while loop
    {
        printf("Counter %d\n", iCounter); // Prints 1
        printf("++ Counter: %d\n", ++ iCounter); // Increments to 2 and prints
        printf("-- Counter: %d\n", -- iCounter); // Decrements to 1 and prints
        printf("Counter ++: %d\n", iCounter ++); // Prints 1 and then increments to 2. 
        //After this line the loop exits, due to increment to 3 in conditrion
    }

return 0;

}