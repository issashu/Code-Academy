#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printStr(char *s);

int main(){
    char string[] = {"Hello world! Did you bring a towel?"};
    char *s = &string[0];
    printStr(s);

}

void printStr(char *s){
    for(int i=0; s[i]!='\0'; i++){
        printf("%c", s[i]);
    }
    printf("\n");
}