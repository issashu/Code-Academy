#include <stdio.h>
int main() 
{
    int i = 0, j = 0;
    printf("i = %d, j = %d\n", i, j); 
    printf("j=i++: %d\n", j=i++); //j is assigned i and after i incremented to 1
    printf("i = %d, j = %d\n", i, j);// i is now 1 and j is 0
    printf("j = ++i: %d\n", j=++i); // i is incremented to 2 and then j is assigned i
    printf("i = %d, j = %d\n", i, j);  // i=2 and j=2
    printf("i--: %d\n", i--); //i = 1
    printf("i = %d, j = %d\n", i, j);// i = 1 and j=2
}