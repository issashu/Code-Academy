#include <stdio.h>

int main()
{
    char str[] = "Hello"; 

    for (int i=0; i<(sizeof(str)/sizeof(str[0])); i++)
    {
        if (str[i] == 'l')
            str[i]='x';
    }
       
    printf("%s\n", str);    
    
}