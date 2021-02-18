/*
Задача 7.
Хванете дълъг стринг и пребройте колко пъти се среща всяка буква от
азбуката в него. Запишете резултата в масив за всяка буква. 

Кода е правен с линейно търсене и брояч. Може да стане с подреждане на стринга по ascii стойности и search tree или
с един троен масив база данни за букви и ascii кодове (големи и малки) и после сравняване и броене (пак линейно)
*/   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int CountLetters(char *String);

int main(){
    char String[80] ={'a'};
    int (*Counting)(char *) = CountLetters;

    printf("Please enter a string (max 80 characters will be read):\n");
    fgets(String, sizeof String, stdin);
    printf("\n\nYou have entered:\n%s", String);

    Counting(String);
}

int CountLetters(char *String){
    int Counter = 0;
    int Length = strlen(String);

    for (int i=0; i<Length-1; i++){
        if(isalpha(String[i])){
            Counter=1;
            for (int j=i+1; j<Length; j++){
                if(String[i] == String[j]){
                    Counter++;
                }
            }
        printf("Letter %c was found %d times\n", String[i], Counter);
        }
    }
}
