/*
Задача 10.
Да намерим простите числа (natural number) до 1000 и да ги сложим в масив.
Да напишем функция, която да ни казва дали дадено число от 0 - до 1000
е просто.
Просто число е се нарича всяко естествено число, по-голямо от 1,
което има точно два естествени делителя – 1 и самото себе си.
Например 5 е просто, защото се дели единствено на 1 и 5, докато 6 не
е, защото се дели освен на 1 и 6, и на 2 и 3.
*/

#include <stdio.h>
#include <stdlib.h>

void FillArray (int *Numbers, int Maxrange);
int CheckPrime(int MaxRange, int *Results);

int main(){
    int MaxNumber = 1000;
    int PrimesArray [1000] = {0};
    int (*IsPrime)(int, int*) = CheckPrime;
    
    /*
    void (*FillNumber)(int *, int) = FillArray;
    FillNumber(PrimesArray, MaxNumber);
    */
    IsPrime(MaxNumber, PrimesArray);

    printf("The prime numbers 0-%d are:\n", MaxNumber);
    for(int i=0; PrimesArray[i]!='\0'; i++){
        printf("%d ,", PrimesArray[i]);
    }

}

/*void FillArray (int *Numbers, int MaxRange){
    for (int i=0; i< MaxRange; i++){
        Numbers[i]=i;
    }
}
*/

int CheckPrime(int MaxRange, int *Results){
    short Counter = 0;

    for (int i = 1; i<MaxRange; i++){
        Counter = 0;
        for (int j = 1; j<MaxRange; j++){
            if(i%j==0){
                Counter++;
            }
        }
        if (Counter==2){
            *Results = i;
            Results++;
        }
    }
}