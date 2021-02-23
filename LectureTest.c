/*Задача 7.
Хванете дълъг стринг и пребройте колко пъти се среща всяка буква от
азбуката в него. Запишете резултата в масив за всяка буква. */
#include <stdio.h>
#include <string.h>

int countLetters(char *p, char *s, int size);

int main(int argc, char **argv) {
    char arr[] = "this is dog";
    char alphabet[25] = {0};
    char c;
    int i = 0;
    int sizeAlpha = (sizeof(alphabet) / sizeof(alphabet[0]))+1;

    printf("Enter text here: ");

   /* while ((c = getchar()) != '\n'){
        arr[i++] = c;
    } */

    char *p = arr;
    char *str = alphabet;

    int (*res)(char *, char *, int) = countLetters;
    res(p, str, sizeAlpha);

    i = 0;
    while(sizeAlpha > 0){
        printf("Letter %c is found %d times.\n", 65 + i, alphabet[i]);
        i++;
        sizeAlpha--;
    }

    return 0;
}

int countLetters(char *p, char *s, int size){
    int counter = 0;
    int lowerCase = 97;
    int upperCase = 65;
    int index = 0;

    for (index=0; index < size; index++) {
        while(*p!='\0') {
            if(*p == lowerCase || *p == upperCase)
                counter++;
            p++;
        }
        lowerCase++;
        upperCase++;
        s[index] = counter;
        //size--;
    }
    return counter;
}