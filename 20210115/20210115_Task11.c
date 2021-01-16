#include <stdio.h>

int main()
{
    char str[] = "Hello";
    char rts[6]; 

    for (int i=0; i<(sizeof(str)/sizeof(str[0])); i++)
        rts[5-i]=str[i]; // Leaving rts[6] for the \0

    for (int i=0; i<(sizeof(rts)/sizeof(rts[0])); i++)
        printf("%c", rts[i]);
    
    printf("\n");

}