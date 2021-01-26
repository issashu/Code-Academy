#include <stdio.h>

int main(){
    char c;
    int counterTab = 0;
    int counterSpace = 0;
    int counterNewline = 0;

    while(c!=EOF){
        c=getchar();

        if (c=='\n'){
            counterNewline++;
        }
        if (c=='\t'){
            counterTab++;
        }
        if (c==' '){
            counterSpace++;
        }
    }

    printf("You typed %d new line characters\n", counterNewline);
    printf("You typed %d TAB characters\n", counterTab);
    printf("You typed %d SPACE characters\n", counterSpace);
}