/*
 Задача 10.
Как работи? Дефинираме променлива “а“, дефинираме пойнтер, но още не му задаваме стойност. 
Отпечатайте адреса на “а”. След това присвояваме стойност на пойнтера, като внимаваме типовете 
на пойнтера и променливата да са от един и същи тип. Отпечатваме на екрана стойността на пойнтера с %р, 
стойността на „а“ с %d, стойността на *ptr с %d.
*/

#include <stdio.h>

int main(){
    int *Pointy = NULL;
    int a = 7;
    Pointy = &a;
    *Pointy += 5;

    printf("Adress of Pointer is %p\n", Pointy);
    printf("Value of adress pointed to is %d\n", *Pointy);
    printf("Value of the variable pointed at is %d\n", a);
}