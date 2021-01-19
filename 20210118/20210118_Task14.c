#include <stdio.h> 

int OnePlusTwo(int n1, int n2);
int TwobyThree(int n1, int n2);
int NineLessFour(int n1, int n2);

int main() 
{
  int nX = 1, nY = 2;
  printf("\nInit values: X= %d, Y= %d\n", nX, nY);
  nX = OnePlusTwo(1,2), TwobyThree(2,3), 3 + 4; // Added functions , but nX becomes the first expression
  nY = ( 7 * 8, 8 + 9, NineLessFour(9,4)); //Added function , nY becomes the last expression...well function
  printf("\nX= %d, Y= %d\n", nX, nY);
  return 0;

}

int OnePlusTwo(int n1, int n2)
{
    return n1+n2;
}

int TwobyThree(int n1, int n2)
{
    return n1*n2;
}

int NineLessFour(int n1, int n2)
{
    return n1-n2;
}