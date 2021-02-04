/*
Задача 1 декларирайте три масива с три елемента: Първият от тип char
Вторият от тип int
Третият от тип double
Отпечатайте размерите на масивите използвайки оператора sizeof(arr);

Задача 1.2 принтирайте последния елемент от декларираните по горе масиви:
Първият от тип char Вторият от тип int Третият от тип double
*/
#include <stdio.h>

int main(){
    char Masiv1[] = "abc";
    int Masiv2[3]={1, 2, 3};
    double Masiv3 [3] = {1.00, 2.50, 3.75};

    printf("Masiv1 is of size: %d\n", sizeof(Masiv1));
    printf("Masiv2 is of size: %d\n", sizeof(Masiv2));
    printf("Masiv3 is of size: %d\n", sizeof(Masiv3));

    printf("The last elements of each array are: %c, %d and %.2lf respectively.\n", Masiv1[2], Masiv2[2], Masiv3[2]);
}