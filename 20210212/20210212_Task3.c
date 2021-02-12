/*
 Задача 3 Напишете функции, с помощта на които да реализирате динамичен масив от елементи, 
 чиято големина може да се променя по време на изпълнение на програмата

 Направих си универсален код, който да мога да копирам при нужда за други програми.
 Може да се използва, като се следи до кой елемент попълваме и ако стигаме края, да се вика realloc и добавят още елементи.
 Става подобно на стд::вектор от С++
*/
#include <stdio.h>
#include <stdlib.h>

/* C11 stuff to study: Как да имитираме templates от C++, за да си направим универсален тип Пойнтер
#define foo(a, b) _Generic((b), char*: foo_char_ptr, int: foo_int)(a, b)
*/

int AllocateMemory (int uSize);
int ReallocateMemory(int *p);
int FreeMemory(int *p);

int *Pointy;

int main(){
    //Variables go here:
    short NrElements = 0;

    //Methods go here:
    printf("Please enter how many elements do you need: \n");
    scanf("%d", &NrElements);
    AllocateMemory (NrElements);
    ReallocateMemory(Pointy);
    FreeMemory(Pointy);
}

int AllocateMemory (int uSize){
    int *Pointy = calloc(uSize, sizeof(int));   
    if (Pointy == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array allocated at %p up to %p\n", Pointy, (Pointy+uSize));
        return 0;
    }
}

int ReallocateMemory(int *p){
    int NewMax = 0;
    printf ("Please enter a new size for the array: \n");
    scanf ("%d", &NewMax);
    Pointy = realloc(p, NewMax * sizeof(int));
    if (Pointy == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array reallocated at %p up to %p\n", Pointy, (Pointy+NewMax));
        return 0;
    }
}

int FreeMemory(int *p){
    free(p);
}