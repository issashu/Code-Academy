/*
Задача 3. Напишете функция, която връща резултат (а+в)*4.
 */

#include <stdio.h>
#include <ctype.h>

short Menu();
void CalcInt();
void CalcFloat();

int main(){
    short MenuSelect = 0;
    MenuSelect = Menu();

    if(MenuSelect==1){
        CalcInt();
    }
    else if (MenuSelect==2){
        CalcFloat();
    }
    else{
        printf("There is no validating spoon. Bye!");
    }
}

short Menu(){
    int selector = 1;

    printf("Please select the type of numbers you will be using:\n");
    printf("1. Integers / Whole Numbers\n");
    printf("2. Floats / Floating point numbers\n");
    scanf("%d", &selector);

    return selector;
}

void CalcInt(){
    int a=0;
    int b=0;

    printf("Please enter two numbers separated by Enter key:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d", (a+b)*4);
}

void CalcFloat(){
    double a = 0.00;
    double b = 0.00;

    printf("Please enter two numbers separated by Enter key:\n");
    scanf("%lf", &a);
    scanf("%lf", &b);

    printf("%.2lf", (a+b)*4.00);
}