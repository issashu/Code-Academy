/*
Задача 2. Напишете функция int printArr(int a[], int l), която получава като първи аргумент началото 
на масив от интеджери, а като втори неговата дължина и принтира всички елементи на масивa един по един
до неговия край.
*/

int printArr(int a[], int l);

//Глобалните променливи работят и без extern, но е по-смислено да са с extern наистина
int Array[5] = {0};

#include <stdio.h>

int main(){
    printf("Please enter 5 integers for the array: \n");
    for (int i=0; i<5; i++){
        scanf("%d", &Array[i]);
    }
    int l = sizeof(int)/sizeof Array[0];

    printArr(Array, l);

}

int printArr(int a[], int l){
    printf("The elements you entered are: ");
    for (int i=0; i<l; i++){
        printf("%d ", a[i]);
    }
}