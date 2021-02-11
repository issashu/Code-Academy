/*
Напишете програма, която да генерира случайна парола от 6 букви докато user-а я хареса.
Вариант 1: може да използвате цикли while/for + стрингове Вариант 2: използвайте функция
Указания:
1. Генерирайте парола
2. Проверете дали потребителя е харесва
3. Повторете докато потребителя си хареса паролата

using http://www.asciitable.com with range 33 - 122 and % to keep rand in range
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char password [6] = {'s'};
    srand(time(0));
    char answer ='n';
    while(answer!='y'){
        printf("generating password, please wait...\n");
        for (int i = 0; i< 6; i++){
            password[i] =  33 + rand()%89;
        }
        printf("Your new password is:\n");
        for (int i = 0; i< 6; i++){
            printf("%c", password[i]);
        }
        printf("\nDo you like it? Press y for yes or anything for no\n");
        scanf("%c", &answer);
    }
}