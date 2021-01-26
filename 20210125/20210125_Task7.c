#include <stdio.h>

int main()
{
    char c;
    int Counter = 0;
    char String[80];

    while((c=getchar())!=EOF)
    {
        for(int i=0; i<=10; i++)
        {
            if(i<10 && c=='\n')
            {
                c=0;
            }
            if(i>=10 && c=='\n')
            {
                putchar(c);
            }

        }
    }
}