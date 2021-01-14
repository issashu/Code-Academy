#include <stdio.h>

int main()
{
    char c = (10-127);

    printf("%d\n", c); //-117
    printf("%c\n", c); // ? unknown char
}