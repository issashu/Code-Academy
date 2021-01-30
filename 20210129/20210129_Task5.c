/*
Задача 5. Напишете програма на С, която чрез функция проверява
дали дадено число е четно или не.
*/

void IsEven(int number);

#include <stdio.h>

int main(){
    int number = 0;
    printf("Enter a number: \n");
    scanf("%d", &number);
    IsEven(number);

}

void IsEven(int number){
    if (number%2 == 0){
        printf("%d is an even number", number);
    }
    else{
        printf("%d is an odd number", number);
    }
}