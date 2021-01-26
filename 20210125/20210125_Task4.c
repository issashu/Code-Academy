#include <stdio.h>

int main(){
    int c;
while ((c = getchar()) != EOF) {
    if (c != ' ') {
        putchar(c);
    } else {
        c = getchar();
        if (c == ' ') {
            putchar(' ');
        } else {
            putchar(' ');
            putchar(c);
        }
   }
}
}