#include <stdio.h>

//All in main

int main()
{
    int a=3;
    int b=5;
    int rez=0;

    rez=3&5;
    printf("AND: %d\n", rez);

    rez=3|5;
    printf("OR: %d\n", rez);

    rez=3^5;
    printf("XOR: %d\n", rez);
}