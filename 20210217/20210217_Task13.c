/*
Задача 13.
Напишете програма, която да прочете низ от потребителя и да го обърне
в обратен ред.
Например: 'xyz' да стане 'zyx
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintBackwards(char *Text);
void Swapper(char *Text, char *Txet);

int main(){
    char String[100] = {'s'};
    char Gnirts[100] = {'s'};
    void (*BackPrinter)(char *) = PrintBackwards;
    void (*SwapME)(char *, char *) = Swapper;

    printf("Please enter a string (max 100 will be considered and stored, due to inventory allowance and item size): \n");
    fgets(String, sizeof String, stdin);
    BackPrinter(String);
    SwapME(String, Gnirts);
    printf("%s", Gnirts);
    
}

void PrintBackwards(char *Text){
    int TextSize = strlen(Text);
    for (int i=TextSize-1; i>=0; i--){
        printf("%c", Text[i]);
    }
}

void Swapper(char *Text, char *Txet){
    int TextSize = strlen(Text);
    for (int i=TextSize-1, j=0; i>=0, j<=TextSize-1; i--, j++){
       Txet[j]=Text[i];
    }
}