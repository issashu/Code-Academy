/*
Задача 5. Пренапишете функцията за сумиране елементите на масив използвайки пойнтер аритметика вместо 
инкрементиращa променливa i:
int sum_array(const int a[], int n){ 
    int i, sum = 0;
    for(i = 0; i < n; i++){ 
        sum += a[ i ];
        return sum; 
    }
*/

#include <stdio.h>

int sum_array(int *a, int n);

int main(){
    int array[5]={3, 4, 5, 6, 7};
    int n = 5;
    int total = 0;
    total = sum_array(array, n);
    printf("%d", total);

}

int sum_array(int *a, int n){ 
    int sum = 0;
    int *max_p = a + n;
    while (a != max_p){ 
        sum += *a;
        a++;
    }
     return sum;
}
