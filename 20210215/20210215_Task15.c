/*
Задача 15.
Ще копираме стрингове. Дефинирайте и инизиалицирайте два стринга: string 1: "A string to be copied."
string3: "I am very good in strings coping!"
Дефинирайте и два празни стринга, в които ще копираме string 2, string4. Дефинирайте функция, която 
през пойнтери ще извърши копирането от стринг към стринг. Използвайте while и факта, че *pointer++ 
отива към следващия символ.
Помислете за терминиращия символ. Принтирайте двата изкопирани стринга.
Извикайте функцията и копирайте от string1 в string4.
*/

#include <stdio.h>
#include <stdlib.h>

void MyStringCopy(char array[], char *pointer);

int main(){
    char string1[] = "A string to be copied.";
    char string2[100] = {'c'};
    char string3[] = "I am very good in strings coping!";
    char string4[100] = {'c'};
    
    char *Pointy = string1;
    char *Pointy2 = string3;

    MyStringCopy(string2, Pointy);
    MyStringCopy(string4, Pointy2);
    MyStringCopy(string4, Pointy);

    printf("%s\n", string2);
    printf("%s\n", string4);
    printf("%s\n", string4);
}

void MyStringCopy(char array[], char *pointer){
    int Counter = 0;
    while(*pointer){
        array[Counter] = *pointer;
        pointer++;
        Counter++;
    }
    array[Counter+1] = '\0';
}