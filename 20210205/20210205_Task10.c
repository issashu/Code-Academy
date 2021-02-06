/*
Задача 10. Напишете функцията strncat(s, t, n), която добавя (конкатенира) n символа от стринга t 
в края на стринга s.
*/

/*
Задача 9. Напишете функцията strncpy(s, t, n), която копира най - много n символа от t в s .
*/
#include <stdio.h>
#include <stdlib.h>

void our_strncpy(char *s, char *t, int n);

int main(){
int n=0;
printf("How many elements to copy?\n");
scanf("%d", &n);
char String1[] = {"This is first string"};
char String2[] = {" and this is also a second string"};
our_strncpy(String1, String2, n);
}

void our_strncpy(char *s, char *t, int n){
short Itterator = 0;
char *Result;
Result=(char*)calloc(40000, sizeof(char));
for(int i=0; s[i]!='\0'; i++){
    Result[i] = s[i];
    Itterator++;
}
for (int i=Itterator, j=0; j<=n; i++, j++){
    Result[i] = t[j];
}
printf("\n%s\n", Result);
free(Result);
}
