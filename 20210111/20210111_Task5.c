#include <stdio.h>
#include <stdbool.h>

bool obarniBitNa (int Number, int Index);


int main()
{
    unsigned int Number = 0;
    int Position = 0;

    printf("Please enter a number:\n");
    scanf("%d", &Number);

    printf("Please enter an index for bit operations:\n");
    scanf("%d", &Position);


    obarniBitNa (Number, Position);
    
}

bool obarniBitNa (int Number, int Index)
{
    printf("Number before bit change %d\n", Number);
    Number ^= (0x1 << Index);//Ex.: 1072 will become 5168 and 5168 will become 1072 if we set bit 12
    printf("Number after bit change %d\n", Number);
    printf("The bit at position %d is: %d", Index, (Number >> Index) & 0x1);
}

