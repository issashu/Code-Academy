#include <stdio.h>

typedef int t_10x_Masiv[10];

int main(){
    t_10x_Masiv Array;

    for (int i=0; i<10; i++){
        Array[i] = i+1;
    }

    for (int i=0; i<10; i++){
        printf("%d ", Array[i]);
    }
}