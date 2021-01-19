#include <stdio.h>

int main()
{ 
    int x = 10;
    int y = 10;
    int z = 30;

    // 1. z < y is 0. 2. y+0 != 20 is 1. 3. x==y is 1. 4. 1 and 1 are 1 again
    int true = x==y+(z < y)!=20;

    printf("%d\n", true);
}
