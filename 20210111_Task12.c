#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned int Number = 0;
    int Position = 0;

    printf("Please enter a number:\n");
    scanf("%d", &Number);

    printf("Number before bit change %d\n", Number);
    Number |= 0x24;     //Ex.: 83 will become 119. 119 won't change though
    printf("Number after bit change %d\n", Number);
    
}