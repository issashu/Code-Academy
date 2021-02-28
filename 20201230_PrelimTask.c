#include <stdio.h>

void Printer();

int main()
{
    char Answer = 'y';

    while (1){
        Printer();
    printf("Do you want to continue?");
    scanf("%c", &Answer);
    if (Answer=='n')
        break;
    }
    
    return 0;
}

void Printer(){
    printf("Hello from the other side!");
}
