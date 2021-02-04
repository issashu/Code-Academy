/*
Задача 7. Напишете функция, която прави същото, както в задача 6 (30!), но е рекурсивна.
*/

#include <stdio.h>

int Recursive(int a);

int main(void){
    //Според гугъл 2.6525286e+32 така е виж моята с е г
    int a = 30;

    printf("Multiplication of 1 through 30 is: %e", Recursive(a));

    return 0;
}

int Recursive(int a){
    if (a == 1){
        return a; 
    } else{
        a *= Recursive(a - 1);
        return a;       
    }
} 