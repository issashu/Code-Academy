/*
Задача 2.Напишете функцията size_t my_strlen(char *s), която връща дължината на стринга подаден в нея. 
Итерирайте по масива докато стигнете знака за край на стринг '\0'. Увеличавайте в една променлива от тип size_t стойността 
и за всяка итерация.size_t обикновено е unsignet long int като размер. Върнете променливата като резултат от функцията.
*/

#include <stdio.h>

int my_strlen(char *s);

int main(){
    char string[100];
    printf ("Please enter a string (maximum 100 characters will be memorized): \n");
    /* Following line tells the compiler to read everything until a newline, then discard the newline from buffer*/
    scanf ("%[^\n]%*c", string);
    printf("\n%s\n", string);
    printf("The entered string is %d chharacters long.\n", my_strlen(string));
}

int my_strlen(char *s){
    int counter=0;
    while (s[counter]!='\0'){
        counter++;
    }

    return counter;
}