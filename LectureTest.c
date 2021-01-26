#include <stdio.h>

int main(){
    char c='!';
    while(c!='?'){
        c=getchar();
        if((c>=97 && c<=122) || (c>=65 && c<=90)){
            putchar(c);
        };
    }
    return 0;
}