/*
Задача 7. Напишете функцията strend(s, t), която връща 1, ако низът t се среща в края на низа s 
и 0 ако това не е изпълнено.


Кода е неоптимизиран и върти из памет извън *s...ще дооптимизирам логиката до Понеделник.
*/

#include <stdio.h>
#include <stdlib.h>

int strend(char *s, char *t);

int main(){
char String1[] = {"This is first string"};
char String2[] = {"and this is also a second string"};
strend(String1, String2);
}

int strend(char *s, char *t){
    int Itterator_s = 0;
    int Itterator_t = 0;
    while(*s){
        s++;
    }
    while(*t){
        t++;
        Itterator_t++;
    }
    while(*t){
        if(*s == *t){
            Itterator_s++;
        }
        s++;
        t++;
    }
    if(Itterator_s == Itterator_t){
        printf("String2 is found at the end of String 1\n");
        return 1;
    }
    else{
        printf("String2 is not found at the end of String 1\n");
        return 0;
    }
}

