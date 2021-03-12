/*
Задача 7.
Напишете програма, която обработва Ctrl+C
Ctrl+D, Ctrl+Z
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 

void SignalPrinter(int signum);

int main(){
    signal(SIGTSTP, SignalPrinter);
    signal(SIGINT, SignalPrinter);
    signal(SIGQUIT, SignalPrinter);
    
    while(1){
        printf("Infinite loop, yo!\n");
    }
    
    
}

void SignalPrinter(int signum){
    switch (signum){
        case SIGINT:
            printf("CTRL+C detected!\n");
            exit(1);
        break;

        case SIGQUIT:
            printf("Program tried to quit.\n");
            exit(1);
        break;

        case SIGTSTP:
            printf("CTRL+Z has been pressed.\n");
            exit(1);
        break;
    }
}