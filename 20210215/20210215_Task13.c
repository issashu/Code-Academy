/*
Напишете програма, която намира дължината на стринг с пойнтер! (без да използва length());
*/

#include <stdio.h>

int main(){
    char Array[] = "I'd far rather be happy than right any day.";
    char *Pointy = Array;
    int Counter =0;

    while(*Pointy){
        Pointy++;
        Counter++;
    }

    printf("The string:\n");
    printf("%s\n", Array);
    printf("is %d characters long", Counter);

}