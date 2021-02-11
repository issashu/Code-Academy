/*
Задача 5. Пренапишете алгоритъма за сортиране без да използвате инкрементиращи променливи.
void sort ( int a[], int n){ 
    int i, j, temp;
    for ( i = 0; i < n - 1; ++i ) 
        for ( j = i + 1; j < n; ++j )
            if ( a[i] > a[j] ) { 
                temp = a[i];
                a[i] = a[j];
                a[j] = temp; 
            }
}
*/

#include <stdio.h>

void sort (int* a, int n);

int main(){
    int MaxNumber = 0;
    int Numbers[5] = {12, 67, 1, 45, 9};

   /* printf("Please enter 5 numbers: \n");
    for (int i=0; i<5; i++){
        scanf("%d", &Numbers[i]);
    }*/
    
    sort(Numbers, 5);

    for (int i=0; i<5; i++){
        printf("%d ", Numbers[i]);
    }
}

void sort ( int *a, int n){ 
    int temp = 0;
    int *counter = a+1;
    int *max_p = a + (n-1);
    for(a;a<=max_p;a++)
        for(counter;counter<=max_p;counter++){
            if(*a>*counter){
                temp = *(a);
                *a = *(counter);
                *(a+1) = temp;
            }
            else{
                a++;
            }
        }
} 