#include <stdio.h>

int main()
{
    char c ='b';
    int i=100;
    long int il=11111;
    long long int ill=1;
    double d=1000000;

    printf("Long long %d\n", sizeof(ill));
    printf("Long %d\n", sizeof(il));
    printf("Int %d\n", sizeof(i));
    printf("Char %d\n", sizeof(c));
    printf("Double %d\n", sizeof(d));
}