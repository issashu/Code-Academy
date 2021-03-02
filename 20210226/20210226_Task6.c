#include <stdio.h>

typedef struct{
    char string[20];
    int var1;
}key_t;

int main(){
    key_t PassKey;

    PassKey.var1 = 200;
    printf("%d", PassKey.var1);
}