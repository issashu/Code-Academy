#include <stdio.h>
#include <stdlib.h>

enum bool{false, true};

int main(void){
  enum bool b = 0;
  switch (b){
    case true:
    printf("True");
    break;

    case false:
    printf("False");
    break;
  }
return 0;
}