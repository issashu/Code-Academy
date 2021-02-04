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
    
}

void reverse(char s[]){
    char temp[100];
    char tmp=0;
    for (int i = 0 , j = strlen(s-1); i<j; i++, j--){
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    for (int c=0; c<strlen(s); c++){
        printf("%c", s[c]);
    }

}