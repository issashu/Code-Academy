/*
Задача 6. Напишете отново функцията void our_strcat(char *s, char *t), която разгледахме преди 
малко като използвате указатели, а не инкрементиращите пrоменливи i, j.
*/

#include <stdio.h>
#include <stdlib.h>

void our_strcat(char *s, char *t);

int main(){
char String1[] = {"This is first string"};
char String2[] = {"and this is also a second string"};
our_strcat(String1, String2);
}

void our_strcat(char *s, char *t){
char *Result;
//Result=(char*)calloc(40000, sizeof(char));
while(*s){
    *Result = *s;
    Result++;
    s++;
}

while(*t){
    *Result = *t;
    Result++;
    t++;
}
*Result ='\0';
printf("\n%s\n", Result);
//free(Result);
}