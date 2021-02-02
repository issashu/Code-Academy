/*
Упражнение 3.* Добавете проверка във функцията int atof(char *s) дали подаденият стринг няма показни 
позиции преди числото и, ако има, ги премахнете. Проверете дали числото не е отрицателно и, ако е така,
включете знака в резултата.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double atof(const char *s);
void RemoveDisplay(char *s);

int main(void){
    char string[] = "   123675.87786954";
    RemoveDisplay(string);
    //DEBUG:
    printf("%s\n", string);
    
    printf("%lf\n", atof(string)); 
}

void RemoveDisplay(char *s){
    int i=0;
    if(s[0]=='-' || s[0]=='+'){
        i++;
    }
    while(s[i]!='\0'){
        if(s[i]=='.'){
            i++;
        }
        if(isdigit(s[i])==0){
            for(int j=i;j<strlen(s);j++)
                s[j]=s[j+1];
        }
        else if(isdigit(s[i])==1){
            i++;
        }
    }
}

double atof(const char s[]){ 
    int i;
    int counter=0;
    int power = 1;
    double n = 0.00;
    while (s[counter]!='.'){
        counter++;
    }
    for(i = 0; s[i] >= '0' && s[i] <= '9' && s[i]!='.'; i++)
        n = 10 * n + (s[i] - '0');
    
    for (i=counter; s[i]!='\0';i++){
        n = 10 * n + (s[i] - '0');
        power*=10;
    }

    return (n/power);
 }