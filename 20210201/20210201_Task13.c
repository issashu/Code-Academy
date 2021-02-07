/*
Задача 13 напишете функцията void lower(char s[]), която преобразува главните 
букви в малки.
*/
#include <stdio.h>
#include <string.h>

void lower(char s[]);

int main(){
    char string [10];
    printf("Enter a string to verify and remove capital letters (max 10 characters will be read):\n");
    scanf("%[^\n]s", string);
    lower(string);
    printf("%s", string);
}

void lower(char s[]){
    for (int i=0; i<strlen(s);i++){
        if(s[i]>=65 && s[i]<=90){
                s[i]+=32;
        }
    }
}