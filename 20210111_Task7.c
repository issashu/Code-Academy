#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned int Number = 0;
    int Position = 0;

    printf("Please enter a number:\n");
    scanf("%d", &Number);

    printf("Number before bit change %d\n", Number);
    Number &= 0xAA;//Ex.: 255 8bit will become 170 if we clear even bits
    printf("Number after bit change %d\n", Number);
    
}
