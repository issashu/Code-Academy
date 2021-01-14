#include <stdio.h>

int main()
{
    char a='a';
    int b=102;
    long c=50000;
    double d=6;
    float e=-48.907;
    
    
    printf("a is at memory address %p, occupies %d bits and has the value of %c\n", &a, sizeof(a), a);
    printf("b is at memory address %p, occupies %d bits and has the value of %d\n", &b, sizeof(b), b);
    printf("c is at memory address %p, occupies %d bits and has the value of %ld\n", &c, sizeof(c), c);
    printf("d is at memory address %p, occupies %d bits and has the value of %.0lf\n", &d, sizeof(d), d);
    printf("e is at memory address %p, occupies %d bits and has the value of %.3f\n", &e, sizeof(e), e);

}