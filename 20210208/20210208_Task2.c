/*
Задача 2. Дефинирайте и инициализирайте двумерен масив с по 5 елемента (5 x 5). 
След като сте готови, направете въвеждане на данните в масива, като четете от 
потребителя със scanf.
*/

#include <stdio.h>

int main(){
    int TheMatrix2D [5] [5];
    printf("Please enter the Matrix: \n");
    for (int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            scanf(" %d ", &TheMatrix2D[i][j]);
        }
    }
    for (int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            printf(" %d ", TheMatrix2D[i][j]);
        }
        printf("\n");
    }


}
