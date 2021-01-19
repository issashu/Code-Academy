#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//The program for type int is a completly randomized sequence of numbers, but initial value is limited between 1 and 6
//The function for type long long int is just folowing the example in the lecture

int TypeInt (unsigned int Acc);
long long int TypeLLInt (long long int Acc);

int main()
{
    int Accum1 = 1;
    long long int Accum2 = 1;
    int Selection=1;
    printf("Please select a type for A: \n");
    printf("1. A of type int. \n");
    printf("2. A of type loing long int. \n");
    scanf ("%d", &Selection);

    switch (Selection)
    {
        case 1:
        TypeInt(Accum1);
        break;

        case 2:
        TypeLLInt(Accum2);
        break;
    }

    return 0;
}

int TypeInt(unsigned int Acc)
{
    //Assigning to Accum a random value between 1 and 6
    srand(time(0));
    Acc = (rand()%6)+1;

    printf("Initial value of Accumulator is %d.\n", &Acc);
    Acc^=Acc<<13;
    printf ("Value of Accumulator after XORSHIFT LEFT by 13: %d\n", Acc);
    Acc^=Acc>>17;
    printf ("Value of Accumulator after XORSHIFT RIGHT by 17: %d\n", Acc);
    Acc^=Acc<<5;
    printf ("Value of Accumulator after XORSHIFT LEFT by 5: %d\n", Acc);

}

long long int TypeLLInt (long long int Acc)
{
    printf("Initial value of Accumulator 2 is %d.\n", &Acc);
    Acc^=Acc<<13;
    printf ("Value of Accumulator 2 after XORSHIFT LEFT by 13: %d\n", Acc);
    Acc^=Acc>>17;
    printf ("Value of Accumulator 2 after XORSHIFT RIGHT by 17: %d\n", Acc);
    Acc^=Acc<<5;
    printf ("Value of Accumulator 2 after XORSHIFT LEFT by 5: %d\n", Acc);
}