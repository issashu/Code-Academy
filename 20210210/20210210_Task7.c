/*
Задача 6. Пренапишете функцията int linear_search(const int a[], int n, int key); използайки пойнтер 
аритмртиката без инкрементиращи променливи.

Използвам Counter+1 на ред 23, за да избегнем нумеротиране на позициите започващо от 0.
*/
#include <stdio.h>

int linear_search(const int a[], int n, int key);

int main(){
    int a[10] = {0};
    int search = 0;
    printf("Please enter max 10 numbers:\n");
    for (int i =0; i<10; i++){
        scanf("%d", &a[i]);
    }
    printf("Please enter a number to look for: \n");
    scanf("%d", &search);
    printf("The number saught is at position %d", linear_search(a, 10, search));

}

int linear_search(const int a[], int n, int key){
    const int *Searchy = a;
    int Counter = 0;

    while (*Searchy < a[n]){
        if(*Searchy == key){
            return Counter+1;
        }
        Counter++;
        Searchy++;
    }
}