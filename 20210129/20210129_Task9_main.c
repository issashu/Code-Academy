/*
Задача 9. Напишете три функции, които да правят изчисление по ваш избор и 
да се извикват по следния начин:

Main вика Ф1; Ф1 вика Ф 2; Ф2 вика Ф3;

Изнесете прототипите им в отделен .h файл.
*/

#include <stdio.h>
#include "20210129_Task9.h"

extern unsigned int number1;
extern unsigned int number2;
extern unsigned int count;


int main(void){
  printf("Please input two numbers.\n");
  printf("Your first number(up to 9 symbols): \n");
  scanf("%ud", &number1);
  printf("Your second number: \n");
  scanf("%ud\n", &number2);
  printf("Your encoded number is: \n");
  printf("Your number is decoding..************.\n");

  for(int i =  countBits(number1); i >= 0; i--){
    printf("%c ", findLetter(codeNumber(number1, i)));
  }
  printf("\n");

  for(int i = countBits(number2) ; i >= 0; i--){
    printf("%c ", findLetter(codeNumber(number2, i)));
  }

  return 0;
}