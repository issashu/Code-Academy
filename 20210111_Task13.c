#include <stdio.h>

int RazlichniBitove (int Number1, int Number2);

int main()
{
    unsigned int Number1 = 0;
    unsigned int Number2 = 0;
    int Counter=0;

    printf("Please enter the first number 0-255:\n");
    scanf("%d", &Number1);

    printf("Please enter the second number 0-255:\n");
    scanf("%d", &Number2);

    Counter=RazlichniBitove (Number1, Number2);

    printf("Between the two numbers there are %d different bits in total", Counter);
    
}

int RazlichniBitove (int Number1, int Number2)
{
    int Counter=0;
    for (int i=0; i<8; i++) // No idea how to do multiple steps without a loop of some kind. LIMITED TO 8BIT check
    {
        (Number1>>1);
        (Number2>>1);

       if ((Number1 & 1) != (Number2 & 1))
       {
           Counter++;
       }
    }

    return Counter;
    
}

