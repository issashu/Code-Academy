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
            for(int i=0; i<(int) Y; i++){\
            X*=X;\
            }\
        }

#define RAISE(TYPE)\
        TYPE to_upper (char X){\
            return (X-32);\
        }

#define DISP(X){\
    printf(“sqrt (%g) = %g\n”, X, sqrt(X));
}

AVG(int)
POWER_OF(float)
RAISE(char)

int main(){
    int x = 6;
    int y = 2;
    float q = 3.2;
    float z = 2.10;
    char w = 'A';

    printf("%d\n", int_average(x, y));
    printf("%.2f\n", float_power_off(z, y));
    printf("%c\n", to_upper(w));
}