/*
Задача 1. Напишете функция, която принтира низ, пойнтера към началото му е подаден като аргумент 
на функцията void printstr(char *s); Не забравяйте, низът винаги завършва с знак за 
терминираща нула '\0', затова проверката в цикъла, който принтира всеки чаръктър, 
трябва да е докато не се стигне този знак.
*/
#include <stdio.h>

void printstr(const char *s);

int main(){
    char string[] = "Red riding hood's trip for happiness";

    printstr(string);

    /*DEBUG:
    char *p = string;
    printf("Main: %s \n", p);
    */

}

void printstr(const char *s){
    int i=0;
    printf("The string is:\n");
    while(s[i]!='\0'){
        printf("%c", s[i]);
        i++;
    }

}