#include <stdio.h>


int main()
{
    char c = (255+10); //clang and gcc give warning here for value being beyond the char max
    printf("%c\n", c); //prints tab
    printf("%d\n", c);//prints 9, since overflow
    printf("%p\n", &c); //clang gives warning here as well that printed value is not refferenced when & omitted
}