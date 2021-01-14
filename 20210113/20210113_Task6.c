#include <stdio.h>

//Дефинирайте променливи със стойност -127, 255, 6 237 498, 4 294 967 292, -9 000 000 000 000 775 845.
//Изведете всяка променлива на екрана със printf()

int main()
{
   char c1 = -127;
   unsigned char c2 = 255;
   int c3 = 6237498;
   unsigned int c4 = 4294967292;
   long long int c5= -9000000000000775845;

   printf("c1 in DEC: %d\n", c1);
   printf("c2 in DEC: %d\n", c2);
   printf("c3 in DEC: %d\n", c3);
   printf("c4 in DEC: %u\n", c4);
   printf("c5 in DEC: %lld\n", c5);

}
