#include <stdio.h>

int main()
{
    char c='!';
    int LetterCounter = 0;
    int NumberCounter = 0;

    while(c!=EOF)
    {
        c=getchar();
        if((c>=97 && c<=122) || (c>=65 && c<=90))
        {
            LetterCounter++;
        }
        else if((c>=48 && c<=57))
        {
            NumberCounter++;
        }
    }
    printf("You entered %d letters and %d numbers.\n", LetterCounter, NumberCounter);
    return 0;
}