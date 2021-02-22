#include <stdio.h>
#include <string.h>
 
int countLetters(char* p);
 
int main(int argc, char **argv) {
    char arr[1000] = {0};
    char c;
    int i = 0;
 
    printf("Enter a message/text: ");
 
    while ((c = getchar()) != '\n'){
        arr[i++] = c;
    }
 
    int length = strlen(arr);
    char *p = *&arr;
    int (*res)(char) = countLetters;
 
    printf("Count of 'a' in the string is: %d", (*res)(p));
 
    return 0;
}
 
int countLetters(char *p){
    int counter = 0;
    char charA = 'a';
 
    while (*p != '\0' ) {
       if(*p == charA)
            counter++;
    }
 
    return counter;
}