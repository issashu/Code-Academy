#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillArray(int *Pointer, int MaxCount);
void PrintPositions(int *Pointer);

int main(){
    srand(time(0));
    int array [5][5] = {0};
    int Position [25] = {0};
    int MaxCount = 25;
    int *Pointy = array;
    int *PointertoPosition = Position;
    FillArray(array, MaxCount);    

    for (; *PointertoPosition; PointertoPosition++){
        printf("%d", *PointertoPosition);
    }
}

void FillArray(int *Pointer, int MaxCount){
    int Counter = 0;

    while (Counter < MaxCount){
        *Pointer = abs(rand()%11);
         Pointer++;
         Counter++;
    }
    for(int i = 0; i < MaxCount; i++){
        if (Pointer[i]>=1 && Pointer[i]<=5){
            *Pointer = i;
             Pointer++;
        }
    }

}

void PrintPositions(int *Pointer){
    for (; *Pointer; Pointer++){
        printf("%d", *Pointer);
    }

}