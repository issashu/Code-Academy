/*
Задача 14*. Напишете функция int getline(char s[],int lim), която чете ред в s[] 
и връща дължината му
*/
#include <stdio.h>
#include <string.h>

int our_getline(char s[], int lim);

int main(){
    int lim = 0;
    char string[100];
    printf("Please enter a string (max 100 characters will be read):\n");
    lim = our_getline(string, lim);
    printf("The string is %d characters long.", lim);
}

int our_getline(char s[], int lim){
    scanf("%[^\n]s", s);
    printf("%s\n", s);
    for(int i=0; s[i]!='\0'; i++){
        lim++;
    }
    return lim;
}

