#include <stdio.h>

void Test();

int main()
{
    Test();
    Test();
    Test();
}

// Best option is to change void to int for the function type and return

void Test()
{
  static int sStatic = 25;
  static int sStaticCounter = 1;

  if (sStaticCounter==3)
  {
    sStatic+=1;
    printf("After 3 calls the static variable is equal to %d\n", sStatic);
  }else
    {
      sStatic+=1;
      sStaticCounter+=1;
    } 
    
}