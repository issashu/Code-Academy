#include <stdio.h>

int main()
{
    char c ='b';
    int i=100;
    long int il=11111;
    long long int ill=1;
    double d=1000000;
    short int si =1;
    unsigned long int uli =1;
    float f=3.3333;


    printf("Long long %d\n", sizeof(ill));
    printf("Long %d\n", sizeof(il));
    printf("Int %d\n", sizeof(i));
    printf("Float %d\n", sizeof(f));
    printf("Short Int %d\n", sizeof(si));
    printf("uLong int %d\n", sizeof(uli));
    printf("Char %d\n", sizeof(c));
    printf("Double %d\n", sizeof(d));
}