#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    char string[80];
    int i=0;

    while((c=getchar())!='\n')
    {
        if(c>=97 && c<=122)
        {
            c-=32;
            putchar(c);
        }
        else
        {
            putchar(c);
        }  
    }
}