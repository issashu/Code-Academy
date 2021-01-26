#include <stdio.h>

int main(){
    char c;
    int counter = 0;

    while(c!=EOF){
        c=getchar();
        counter++;
    }

    printf("You typed %d characters", counter);
}