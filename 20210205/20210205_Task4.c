/*
Задача 4. Напишете финкцията int our_strcmp(char *s, char *t), която сравнява низовете s и t и връща нула 0 
ако двата низа са равни. Ако елемента в който се различават s[i] е по-малък от t[i] връща стойност по- малка от нула < 0. 
Ako s[i] е по-голям от t[i] връща стойност по-голяма от нула > 0

Задачата работи и може да се види и пусне тук:
https://codecollab.io/@issashu/Strypes%20lessons

Поради каквато и да е причина ВС Код не харесва main в кода по-долу:
*/

#include <stdio.h>

int our_strcmp(char *s, char *t);

int main(){
    short answer = -3;
    char String1[] = {"This is the first one string"};
    char String2[] = {"This is the second twotwotwo string"};
    answer = our_strcmp(String1, String2);

    if(answer==0){
        printf("The two strings are equal in lenght\n");
    }
    else if (answer==-1){
        printf("First string is shorter then the second one.\n");
    }
    else if (answer == 1){
        printf("First string is longer then the second one.\n");
    }
    else{
        printf("There has been a malfunction. Buhbye!");
    }
}

int our_strcmp(char *s, char *t){
    int s_counter = 0;
    int t_counter = 0;
    for (int i=0; s[i]!='\0'; i++){
        s_counter++;
    }
    for (int i=0; t[i]!='\0'; i++){
        t_counter++;
    }
    if (s_counter==t_counter)
        return 0;
    else if (s_counter>t_counter)
        return 1;
    else if (s_counter<t_counter)
        return -1;
}