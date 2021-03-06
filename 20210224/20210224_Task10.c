/*
Задача 10.
 Напишете функциите като макроси:
1. функция AVG(x, y), която смята средното аритметично на две подадени
като параметър числа.
2. функция AVG, която смята средното аритметично на числата от
определен диапазон.
3. Напишете функцията повдигане на степен, която повдига х на степен у
4. Напишете функцията TOUPPER, която прави малката буква а в голяма А
5. Напишете функцията DISP((f), (x)), която показва резултата от функции
връщащи double като корен квадратен. DISP(sqrt, 3.0)
 Макрото трябва да се експандне до printf(“sqrt (%g) = %g\n”, 3.0, sqrt(3.0));
*/
#include <stdio.h>
#include <math.h>

#define AVG(TYPE)\ 
       TYPE TYPE ##_average(TYPE X, TYPE Y){\
        return (X+Y)/2;\
        }

#define POWER_OF(TYPE)\
        TYPE TYPE ##_power_off(TYPE X, int Y){\
            return pow(X,Y);\
        }

#define RAISE(TYPE)\
        TYPE to_upper (char X){\
            if(X>=97 && X<=122){\
                return (X-32);\
            }\
            else if(X>=65 && X<=90){\
                return X;\
            }\
            else{\
                printf("Not a letter!");\
            }\
        }

#define DISP(TYPE)\
        TYPE SquareRt (TYPE n){\
            printf("sqrt (%g) = %g\n", n, sqrt(n));\
        }

AVG(int)
POWER_OF(float)
RAISE(char)
DISP(float)

int main(){
    int x = 6;
    int y = 2;
    float q = 3.2;
    float z = 2.10;
    char w = 'a';

    printf("%d\n", int_average(x, y));
    printf("%.2f\n", float_power_off(z, y));
    printf("%c\n", to_upper(w));
    SquareRt (z); 
}