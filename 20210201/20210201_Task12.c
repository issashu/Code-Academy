/*
Задача 12 напишете функцията int any(char s1[], char s2[]), която връща първата 
позиция в низа s1, където се появява някой от символите в низа s2 
(Стандартната библиотечна функция strpbrk извършва тази функция)
*/
#include <stdio.h>

int any(char s1[], char s2[]);

int main(){
    char string1[] = "This is dog";
    char string2[] = "Yes, this is also dog";
    int flag =0;
    printf("Please enter two strings to compare (max 10 characters will be read for each):\n");
    /*scanf("%[^\n]s", string1);
    scanf("%[^\n]s", string2);*/
    flag = any (string1, string2);

    if(flag==0){
        printf("There are no common characters in the two strings.\n");
    }
    else if(flag>0){
        printf("The first common character is at position %d", flag);
    }

}

int any(char s1[], char s2[]){
    int counter = 0;

    while(counter==0){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(s1[i]==s2[j]);
                counter=j;
                return counter;
            }
        }
    }
}