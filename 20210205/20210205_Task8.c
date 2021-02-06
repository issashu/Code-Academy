/*
Задача 8. Напишете функците atoi, itoa, atof и reverse, които писахме преди като използвате указател 
вместо индексиране на масив.

Във ВС Код задачата дава грешка (поне при мен), заради това, ето пак линк към Коуд Колаб,
където си работи:

https://codecollab.io/@issashu/Lessons

*/
#include <stdio.h>
#include <stdlib.h>

void reverse(char *s);
double atof(char *s);
int atoi(char *s);

int main(){
    char String1[] = "Iordan";
    char String2[] = "1234.567890";
    char String3[] = "12345";

    reverse(String1);
    printf("%s\n", String1);
    printf("%lf\n", atof(String2));
    printf("%d\n", atoi(String3));


}

void reverse(char *s){
/* reverse has two pointers: One at begining and one at end of string. They swap places via proxy
variable, until they meet at the middle.*/
    int counter=0;
    char temp = 0;
    char *start = s;
    char *end = s;
    while( *(s+counter) != '\0'){
        counter++;
    }
    for (int c = 0 ; c < ( counter - 1 ) ; c++ ){
        end++;
    }

    for (int i = 0 ; i < counter/2 ; i++ ) {        
      temp = *end;
      *end = *start;
      *start = temp;
 
      start++;
      end--;
   }
}

double atof(char *s){ 
    int i=0;
    int counter=0;
    int power = 1;
    double n = 0.00;
    while ( *(s+counter) !='.'){
        counter++;
    }
    for(; *(s+counter) >= '0' && *(s+counter) <= '9' && *(s+counter)!='.'; s++)
        n = 10 * n + (*(s+counter) - '0');
    
    for (i=counter; *(s+i)!='\0';i++){
        n = 10 * n + (*(s+i) - '0');
        power*=10;
    }
    return (n/power);    
 }

 int atoi(char *s){ 
    int i=0;
    int counter=0;
    int power = 1;
    double n = 0.00;
    while ( *(s+counter) !='.'){
        counter++;
    }
    for(; *(s+counter) >= '0' && *(s+counter) <= '9'; s++)
        n = 10 * n + (*(s+counter) - '0');
    
    return (n);    
 }