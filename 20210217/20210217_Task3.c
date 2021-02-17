/*
Задача.3. Направете масив от указатели към функции по
следния начин:
void add(){...}
void fun2(){...}
void fun3(){...}
void (*func_ptr[3])() = {fun1, fun2, fun3};
Направете меню, с което да питате потребителя коя от
горните функции иска да използва – събиране, изваждане,
умножение и деление. След това попитайте за числата, които
да участват в тази операция, и извикайте функцията, която да
извърши желаната операция.
*/
#include <stdio.h>

int fnPlus(int nA, int nB);
int fnMinus(int nA, int nB);
int fnMulti(int nA, int nB);
int fnDiv(int nA, int nB);
void Menu (int *Num1, int *Num2, int *Select);

int main() {
    int Num1=0;
    int Num2=0;
    int Selector = 0;
    Menu(&Num1, &Num2, &Selector);
    int (*func_ptr[])(int, int) = {fnPlus, fnMinus, fnMulti, fnDiv};
    
    /*DEBUG:
    printf("%d\n", Num1);
    printf("%d\n", Num2);
    printf("%d\n", Selector);
    */
    printf("%d", (*func_ptr[Selector-1])(Num1, Num2));
}

void Menu(int *Num1, int *Num2, int *Select){
    printf("Please enter two values:\n");
    scanf("%d", Num1);
    scanf("%d", Num2);
    printf("Please select an operation from below:\n");
    printf("1. Addition\n");
    printf("2. Substraction\n");
    printf("3. Multiplication\n");
    scanf("%d", Select);
}

int fnPlus(int nA, int nB) { 
    return(nA + nB); 
}
int fnMinus(int nA, int nB) { 
    return(nA - nB); 
}

int fnMulti(int nA, int nB){
    return (nA * nB);
}

int fnDiv(int nA, int nB){
    return(nA / nB);
}