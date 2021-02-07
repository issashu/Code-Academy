/*
Задача 11 напишете функция void squeeze(char s[], int c), която премахва символа с 
от низа s[]
*/
#include <stdio.h>

void squeeze(char *s, char c);

int main(){
    char string[]="This is a string";
    char symbol = 'h';
    scanf("%c", &symbol);
    squeeze(string, symbol);
    printf("%s\n", string);
}

void squeeze(char *s, char c){
    int i=0;

    while(s[i]!=c){
        i++;
    }
    if (i!=0){
        for (i; s[i]!='\0';i++){
            s[i] = s[i+1];
        }
    }
}