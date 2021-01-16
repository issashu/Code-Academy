#include <stdio.h>

int gGlobal;

void Test();

int main()
{
    Test();
    Test();
    Test();

    printf("%d", gGlobal);
}

int gGlobal =0;

void Test()
{
  gGlobal +=1;
}