#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[] = "HELLO";

    for (int i=0; i<(sizeof(str)/sizeof(str[0])); i++)
    {
        if (isupper (str[i]))
            str[i] = tolower(str[i]);
    }

   printf ("%s", str);
} 