/*
Задача 5.
Напишете функция, принтираща сигналите, които й се подават. 
Обработка на сигнали signal.h

https://www.cs.princeton.edu/courses/archive/spring04/cos217/lectures/Signals.pdf

ПРЕДИ ПУСКАНЕ ДА СЕ ЗАКОМЕНТИРА РЕД 28 или си подгответе тск мениджър/2ра конзола
*/
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void SignalPrinter(int signum);

int main(){
    int *pointy = NULL;
    signal(SIGSEGV, SignalPrinter);
    signal(SIGINT, SignalPrinter);
    signal(SIGQUIT, SignalPrinter);
    while(1){
        *pointy = 1;
    }
    
    
}

void SignalPrinter(int signum){
    switch (signum){
        case 11:
            printf("Seg. fault signal caught!");
        break;

        case 2:
            printf("CTRL+C detected!");
        break;

        case 3:
            printf("Program tried to quit.");
            exit(1);
        break;
    }
}
