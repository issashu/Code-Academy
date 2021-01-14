#include <stdio.h>

int main()
{
    char a= -10;
    unsigned char z=0;
    char c = (a+z); 
    printf("%c\n", c); // prints ?
    printf("%d\n", c); //priunts normal -10
    printf("%p\n", &c); //memorry hex gibb
}