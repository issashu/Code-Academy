#include <stdio.h>

//Дефинирайте променливи със стойност
//4.9876543, 7.123456789012345678890, 18 398 458 438 583 853.28, 18 398 458 438 583 853.39875937284928422.
//Изведете всяка променлива на екрана със printf()


int main()
{
   double c1 = 4.9876543; 
   long double c2 = 7.123456789012345678890;
   double c3 = 1839845843858853.28;
   long double c4 = 18398458438583853.39875937284928422;

   printf("c1: %.7F\n", c1);
   printf("c2: %.21LF\n", c2);
   printf("c3: %.3f\n", c3);
   printf("c4: %.21LF\n", c4);

}