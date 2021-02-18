/*
Задача 11.
Напишете програма, която да генерира парола с малки букви (i),
специални символи (j), големи букви (k) и цифри (l), ама разбъркано.
Използвайте функции.

using http://www.asciitable.com with range 33 - 122 and % to keep rand() tamed :P.

Правена е с фиксиран нимер юнаци, НО може да се направи и със четене от конзолата, колко знака искаме.
Имаме една външна promenliwa, ако искаме тази програма да си я ползваме и другаде.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PassGen(char *PassString);
extern char Password [12] = {'s'};

int main(){
    srand(time(0));

    char answer ='n';
    void (*PasswordGenerator)(char *) = PassGen;

    while(answer!='y'){
        printf("generating password, please wait...\n");
        PasswordGenerator(Password);

        printf("Your new password is:\n");
        for (int i = 0; i< 12; i++){
            printf("%c", Password[i]);
        }

        printf("\nDo you like it? Press y for yes or anything for no\n");
        scanf("%c", &answer);
    }

    printf("Please write down your password, before closing the console window:\n");
        for (int i = 0; i< 12; i++){
            printf("%c", Password[i]);
        }
}

void PassGen(char *PassString){
    for (int i = 0; i< 12; i++){
        PassString[i] =  33 + rand()%89;
    }
}