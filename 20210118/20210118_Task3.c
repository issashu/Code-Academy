#include <stdio.h>

int main()
{
    int x = 10;
    int y = 10;
    int false = 0;
    //1. x becomes 11 2. 11 OR 10 becomes 1
    int true = ++x||y;

    printf("%d\n", true);
}