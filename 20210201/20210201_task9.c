/*
Задача 9. Използвайте do-while цикъл, за да напишете функцията 
void itoa(int n, char s[ ]), която преобразува число в символен низ 
(обратната функция на atoi). do-while цикълът e необходим, тъй като в масива s[ ] 
ще трябва да се постави поне един символ, дори ако n е нула. Ако n = 123, за да вземем
последната цифра, трябва да разделим n по модул(%) на основата на бройната система 10.
За да получите чаръктър число, трябва да съберете резултата с '0' т.е. 48. 
За да вземете следващото число, трябва да разделите n на 10. 
Това продължава докато n е различно от нула. Това генерира низа в обратен ред – 321, 
затова използваме функцията reverse(char s[]); от задача 18 , за да обърнем низа.
*/

#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);


int main(){
    int number = 245;
    char s[10];
    itoa(number, s);
    reverse(s);
    printf("%s\n", s);
}

void itoa(int n, char s[]){
    char NegativeFlag ='n';
    int i=0;

    if (n<0){
        NegativeFlag = 'y';
    }

    do{
        s[i] = n%10 +'0';
        i++;
        n/=10;
    }while(n>0);

    if(NegativeFlag=='y'){
        s[i]='-';
        i++;
        s[i]='\0';
    }
    else{
        s[i]='\0';
    }
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