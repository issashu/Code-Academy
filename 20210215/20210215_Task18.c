/*
Задача 18. Връщаме се на кода написан в задача 17. Нека сега
отпечатаме стринговете с
декрементиране, започвайки отзад-напред.
*to -- = *from --;
Проверете готовата функция strlen.
https://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm
Помислете как да направите проверка във функцията за копиране, дали
размерът на стринга, в който копираме, не е по-малък от размера на
стринга, от който копираме, и какво да се случва тогава.
*/

#include <stdio.h>
#include <string.h>

int main(){
    char string1[] = "A string to be copied.";
    char string2[100];
    char string3[] = "I am very good in strings coping!";
    char string4[100];

    memset(string2,0,100);
    memset(string4,0,100);

    strcpy(string2, string1);
    strcpy(string4, string3);

    printf("%s\n", string2);
    for (int)
    printf("%s\n", string4);
}