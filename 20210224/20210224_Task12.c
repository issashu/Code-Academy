/*
Задача 12.

Напишете макро GENERIC_MAX(type)
,което трябва да се експандне до следната функция:
int int_max(int x, int y){
return x > y ? x : y;
}
или
float float_max(float x, float y){
return x > y ? x : y;
}
или
char char_max(char x, char y){
return x > y ? x : y;
}
*/
#include <stdio.h>

#define GENERIC_MAX(TYPE) \
    TYPE TYPE##_max(TYPE x, TYPE y){\
        return x > y ? x : y;\
    }

GENERIC_MAX (int)
GENERIC_MAX (float)
GENERIC_MAX (char)

int main(){
    int a = 0;
    float b=0.00;
    char c ='q';

    a = int_max(2,3);
    b = float_max(2.3, 4.56);
    c = char_max('c', 'u');

    printf(" a is: %d\n b is: %f\n c is: %c", a, b, c);
}