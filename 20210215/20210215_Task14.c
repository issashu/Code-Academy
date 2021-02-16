/*

copy paste na 9ta ot 10.02.2021

Решете задачата за генериране на 6 буквена парола с пойнтери.

Using http://www.asciitable.com with range 33 - 122 and % to keep rand in range

BUG: On no answer, does while twice for som reason.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));

    char answer ='n';
    
    while(answer!='y'){
        char password [6] = {'s'};
        char *PassPoint;
        char *end = password + 5;
        char *start = password;
        printf("generating password, please wait...\n");
        for (PassPoint=start; PassPoint <= end; PassPoint++){
            *PassPoint =  33 + rand()%89;
        }
        printf("Your new password is:\n");
        for (PassPoint=start; PassPoint <= end; PassPoint++){
            printf("%c", *PassPoint);
        }
        printf("\nDo you like it? Press y for yes or anything for no\n");
        scanf("%c", &answer);
    }
}