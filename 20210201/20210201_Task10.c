/*
Задача 10. Напишете функция void itob(int n, char s[], int b), която преобразува цяло
число n в низ s базиран на основа b. Например itob( n, s[], 16) представя числото n 
като шеснадесетично число в стринга s[]
*/
#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);


int main(){
    int number = 0;
    char s[10];
    int base = 10;
    printf("Please enter a number to convert to string:\n");
    scanf("%d", &number);
    printf("Please enter a base to convert to (enter 2, 10 or 16, otherwise results will be erroneous):\n");
    scanf("%d", &base);
    itob(number, s, base);
    reverse(s);
    printf("%s\n", s);
}

void itob(int n, char s[], int b){
    char NegativeFlag ='n';
    int i=0;

    if (n<0){
        NegativeFlag = 'y';
    }

    do{
        s[i] = n%b +'0';
        i++;
        n/=b;
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