#include <stdio.h>
#include <stdbool.h>

bool iz4istiBitna (int Number, int Index);


int main()
{
    unsigned int Number = 0;
    int Position = 0;

    printf("Please enter a number:\n");
    scanf("%d", &Number);

    printf("Please enter an index for bit operations:\n");
    scanf("%d", &Position);


    iz4istiBitna (Number, Position);
    
}

bool iz4istiBitna (int Number, int Index)
{
    printf("Number before bit change %d\n", Number);
    Number &= ~(0x1 << Index);//Ex.: 48 will become 16 if we clear bit 5
    printf("Number after bit change %d\n", Number);
    printf("The bit at position %d is: %d", Index, (Number >> Index) & 0x1);
}

