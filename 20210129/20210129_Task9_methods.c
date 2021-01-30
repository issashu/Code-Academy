#include <stdio.h>
#include "20210129_Task9.h"

unsigned int countBits(unsigned int number){
  int counter = 0;
  int bit = 0;
  while (number){
    counter++;
    number >>= 1;
  }
  bit = counter / 4;
  if (counter % 4 != 0){
    bit++;
  }
  return bit; 
}

unsigned int codeNumber (unsigned int number1, unsigned int count) {
  unsigned int convertedNumber = number1;
  convertedNumber >>= (count-1) * 4;
  return convertedNumber % 16;
}

char findLetter(unsigned int convertedNumber) {
  if(convertedNumber < 0 || convertedNumber > 15){
    printf("The current element of the code has no viable information to be deschiferred!\n");
    return 'X';
  }
  char letters[] = {' ', 'G', 'H', 'I', 'L', 'M', 'N', 'O', 'P', 'R', 'A', 'B', 'C', 'D', 'E', 'F'};
  return letters[convertedNumber];
}
