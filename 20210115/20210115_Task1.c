#include <stdio.h>

int gGlobal;

int main()
{
    int Local=10;
    printf("gGlobal is global variable and is: %d\n", gGlobal);
    printf("Local is local variable and is: %d\n", Local);
}

int gGlobal=321;