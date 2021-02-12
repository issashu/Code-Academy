/*
Ако x е реално число, а y — естествено, то степен се дефинира по следния начин: x на степен 
y = x.x. ... .x (y пъти) Когато y < 0, то x на y = 1 / x -y . 
Валидни са свойствата (x 0): x y = x y-1 .x x y = x y+1/x x y1+y2 = x y1 .x y2 x y1 .y2 = (x y1 ) y2
Тривиалната реализация за пресмятане на x y е чрез извършване на y последователни умножения.

Предполагам, че се изисква пресмятане x на степен y  със заделяне динамично на памет?
Направил съм един array, който се пълни с Х, докато стигне y елемента, като се увелизава на всеки 5 стъигнати.
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    int x=0;
    int y=0;
    int ArraySize=5;
    int MultiplySum=1;
    int *Result = calloc(ArraySize, sizeof(int));
    printf("Please enter a value that needs to be calculated (X): \n");
    scanf("%d", &x);
    printf("Please enter a value for the power of (Y):\n");
    scanf("%d", &y);
    if(y==0){
        printf("%d power %d is %d", x, y, MultiplySum);
        return 0;
    }
    for(int i = 0; i<y; i++){
        Result[i]=x;
        if (i == ArraySize - 1) {
            Result = realloc(Result, ArraySize * sizeof(int));
            if (!Result) {
                printf ("Realloc failed!!!\n");
            }
            ArraySize+=5;
        }   
    }
    for(int i=0; i<y; i++)
    {
        MultiplySum*=Result[i];
    }
    printf("%d power %d is %d", x, y, MultiplySum);
    free(Result);
}