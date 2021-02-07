/*
Задача 10. Напишете функция void itob(int n, char s[], int b), която преобразува цяло
число n в низ s базиран на основа b. Например itob( n, s[], 16) представя числото n 
като шеснадесетично число в стринга s[]
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