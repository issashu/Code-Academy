#include <stdio.h>

void Setter(int (*Matrix)[2]);
void Printer(int (*Matrix)[2]);

int main(){
    int TheMatrix2D [2][2];
    Setter(TheMatrix2D);
    Printer(TheMatrix2D);
}

void Setter(int (*Matrix)[2]){
    printf("Please enter the Matrix: \n");
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            fgets(&Matrix[i][j],4,stdin);
            //scanf("%d", &Matrix[i][j]);
        }
    }
}

void Printer(int (*Matrix)[2]){
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf(" %d ", Matrix[i][j]);
        }
        printf("\n");
    }
}