#include <stdio.h>
#include <string.h>

char reverse(char string[]);

int main()
{
    char c;
    char s[10];
    int i=0;

    while ((c=getchar()) != EOF)
    {
            s[i]=c;
            i++;
    }

    reverse(s);
}

char reverse(char string[])
{
    int i = 10;
    int j = 0;
    char reversed[10];
    for ( int i=0, j=strlen(string)-1; j>=0 ; i++, j--)
    {
        reversed[j] = string[i];
    }
    for (i=0; i<10; i++)
    {
        printf("%c", reversed[i]);
    }

}