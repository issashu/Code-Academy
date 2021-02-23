/*
 Задача 11.
Направете обединение с елементи тип int, int, char. Дайте стойност на елементите един 
по един -7,10 и “c” и изведете тези стойности на конзолата.
Инициализирайте и трите и изведете стойностите им на конзолата.
*/

#include <stdio.h>
#include <stdint.h>

union together{
    int Var1;
    int Var2;
    char Var3;
};

int main(){
    union together Obedineni;

    Obedineni.Var3 = 'c';
    printf("The char variable is: %c\n", Obedineni.Var3);

    Obedineni.Var1 = -7;
    printf("The int negative variable is: %d\n", Obedineni.Var1);
    printf("The char variable is: %c\n", Obedineni.Var3);

    Obedineni.Var2 = 10;
    printf("The positive variable is: %d\n", Obedineni.Var2);
    printf("The int negative variable is: %d\n", Obedineni.Var1);
    printf("The char variable is: %c\n", Obedineni.Var3);
}