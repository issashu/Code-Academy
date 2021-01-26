#include <stdio.h>

int main(){
    char c;
    int counter = 0;

    while(c!=EOF){
        c=getchar();

        if (c=='\n'){
            counter++;
        }
        
    }

    printf("You typed %d new line characters", counter);
}