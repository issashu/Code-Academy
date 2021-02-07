/*
Задача 8 Напишете функция void reverse(char s[]), която обръща низа char s[ ]. 
Използвайте for цикъл с два аргумента, разделени със запетая
i = 0, j = strlen(s) – 1; i < j; i++, j-- , за да обърнете стринга.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(){
    char s[] = {"Hello"};
    reverse(s);
    printf("%s", s);
}

void reverse(char s[]){
    char tmp=0;
    int counter =0;
    while (s[counter]!='\0'){
        counter++;
    }
    for (int i = 0 , j = counter-1; i<j; i++, j--){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }  
}