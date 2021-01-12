#include <stdio.h>
#include <stdbool.h>

bool VzemiBitna (unsigned int Number, int Index);

int main()
{
unsigned int Number = 0;
int Position = 0;

printf("Please enter a number:\n");
scanf("%d", &Number);

printf("Please enter an index for bit operations:\n");
scanf("%d", &Position);

printf("The bit at position %d is: %d", Position, VzemiBitna (Number, Position));
}

bool VzemiBitna (unsigned int Number, int Index)
{
    return (Number >> Index) & 0x1;
}