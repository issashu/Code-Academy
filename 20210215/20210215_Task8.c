/*
Дефинирайте и инициализирайте променлива и пойнтер към нея. Отпечатайте адреса на пойнтера с %p с printf.
*/


#include <stdio.h>

int main(){
    int *Pointy = NULL;
    int a = 7;
    Pointy = &a;
    *Pointy += 5;

    printf("%p", Pointy);
}