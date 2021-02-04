/*
Задача 3.Напишете функцията int linSearch(int a[], int l, int d), която получава като първи 
аргумент началото на масив а, втория аргумент е дължината на масива, а третия аргумент е 
числото, което търсим. Претърсете масива елемент по елемент и ако някой елемент съвпада с 
търсеното число върнете позицията на която се намира този елемент. В противен случай върнете – 1.
*/

#include <stdio.h>

int LinSearch(int array[], int l, int d);

int main(){
    int array[100]={0};
    int n=0;
    int search=0;

    printf("Enter number of elements for the array\n");
    scanf("%d", &n);

    printf("Enter %d integers as elements of the array\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Now, what droid are we looking for? \n");
    scanf("%d", &search);
    
    LinSearch(array, n, search);

}

int LinSearch(int array[], int l, int d){
    char flag = 0;
    for (int i=0; i<l; i++){
        if(array[i]==d){
            printf("%d was found at position %d", d, i+1);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Not found! %d isn't present in the list.\n", d);
        return -1;
    }
}