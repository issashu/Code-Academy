#include <stdio.h>

int main()
{
    char x = 8;
    printf("%d\n", x);
    x = x - 2;
    printf("%d\n", x);
    x = x + 6;   
    printf("%d\n", x);
    x = x - (10+2);

    printf("%d\n", x);
    printf("%c\n", x);
}
