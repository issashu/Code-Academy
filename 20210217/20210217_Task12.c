/*
Задача 12.
Напишете програма, която да генерира парола с малки букви (i),
специални символи (j), големи букви (k) и цифри (l), ама разбъркано.
Използвайте функции.
Насоки:
1. Въвежда се дължина на паролата, колко символа от нея са малки
букви (a..z), големи букви( A..Z ), колко са цифрите (0..9), колко
специални символи (@#$%!^&*).
2. Използва се генератор на случайни числа за символите и тяхната
позиция
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PassGen(char *PassString, int MaxLength);
extern char Password [32] = {'s'};

int main(){
    srand(time(0));

    char answer ='n';
    int PassLength = 0;
    void (*PasswordGenerator)(char *, int) = PassGen;

    printf("Please specify, how long the password needs to be (maximum is 32 characters, but consult with your IT Administrator):\n");
    scanf("%d", &PassLength);

    while(answer!='y'){
        printf("generating password, please wait...\n");
        PasswordGenerator(Password, PassLength);

        printf("Your new password is:\n");
        for (int i = 0; i< PassLength; i++){
            printf("%c", Password[i]);
        }

        printf("\nDo you like it? Press y for yes or anything for no\n");
        scanf("%c", &answer);
    }

    printf("Please write down your password, before closing the console window:\n");
        for (int i = 0; i< PassLength; i++){
            printf("%c", Password[i]);
        }
}

void PassGen(char *PassString, int MaxLength){
    for (int i = 0; i< MaxLength; i++){
        PassString[i] =  33 + rand()%89;
    }
}