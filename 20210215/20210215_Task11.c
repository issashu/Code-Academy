/*
 Задача 11.
Напишете програма, която умножава 2 числа, като използва пойнтер-и.
Пойнтер-ите не са страшни. Дефинират се като тип *Х и се използват като *Х. 
Както променливите, но със * отпред (и 1 наум!).
Продължение: Опитайте да умножите 2 променливи от различен тип, използвайки пойнтери - Резултата ще е:
https://recepti.gotvach.bg/r-9980-Миш-маш_по_селски

Ще се получи, със сигурност ще е вкусно, но няма да има нищо общо с двете променливи или математиката зад тях.
*/

#include <stdio.h>

int main(){
    int *Pointy = NULL;
    int *Pointy2 = NULL;
    int a = 7;
    int b= 3;
    Pointy = &a;
    Pointy2 = &b;
    int c = (*Pointy) * (*Pointy2);
    printf("%d", c);
}