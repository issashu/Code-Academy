/*
Задача 5. Напишете функцията void our_strcat(char *s, char *t), която добавя (конкатенира) стринга t 
в края на стринга s. С един фор цикъл трябва да се стигне до края на низа s и след това на всяка 
следваща трябва да се копират елементите на низа t. Функцията strcat() предполага, че има достатъчно
в s за да се копират всички стойности на низа t, защото иначе оператор за присвояване може да работи
извън размера на масива и да имаме грешка. Но не сме разгледали динамичното заделяне на памет с malloc.
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
short Itterator = 0;
char *Result;
Result=(char*)calloc(40000, sizeof(char));
for(int i=0; s[i]!='\0'; i++){
    Result[i] = s[i];
    Itterator++;
}
for (int i=Itterator, j=0; t[j]!='\0'; i++, j++){
    Result[i] = t[j];
}
printf("\n%s\n", Result);
free(Result);
}
