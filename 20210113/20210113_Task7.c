#include <stdio.h>

//7. Дефинирайте променливи със стойност 24 212, -1 357 674, 1 357 674, -1 357 674 000, 3 657 895 000.
//Изведете всяка променлива на екрана със printf()

int main()
{
   short int c1 = 24212;
   int c2 = -1357674;
   int c3 = 1357674;
   int c4 = -1357674000;
   unsigned int c5= 3657895000;

   printf("c1 in DEC: %d\n", c1);
   printf("c2 in DEC: %d\n", c2);
   printf("c3 in DEC: %d\n", c3);
   printf("c4 in DEC: %d\n", c4);
   printf("c5 in DEC: %u\n", c5);

}
