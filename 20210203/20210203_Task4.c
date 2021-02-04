/*
Задача 4.Напишете функцията int binarySearch(int a[], int n, int x), която получава като 
първи аргумент началото на масив а, втория аргумент е дължината на масива, а третия аргумент 
е числото, което търсим. Знаем, че масива в който ще търсим елемента е предварително подреден. 
Сравняваме тъсения елемент с елемента в средата на масива. Ако той е по голям от този в средата 
търсим елемента от средата до края, ако е по- малък го търсим в частта от началото до средата. 
Това се повтаря, докато елемента от масива не стане равен с търсения. Тогава връщаме номера на 
който се намира елемента в масива или -1 ако не се съдържа в масива.
*/

#include <stdio.h>

int BinarySearch (int array[], int n, int search);

int main(){
    
    int n = 0;
    int array[100]={0};
    int search = 0;

    printf("Enter number of elements for the array\n");
    scanf("%d", &n);

    printf("Enter %d integers as elements of the array\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Now, what droid are we looking for? \n");
    scanf("%d", &search);

    BinarySearch(array, n, search);
}

int BinarySearch (int array[], int n, int search){
    int first = 0;
    int last = 0;
    int middle = 0;

    last = n-1;
    middle = (first+last)/2;

    while (first <= last) {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search) {
            printf("%d found at location %d.\n", search, middle+1);
        break;
    }
        else
            last = middle - 1;

    middle = (first + last)/2;
  }
  
    if (first > last){
      printf("Not found! %d isn't present in the list.\n", search);
      return -1;
    }

    return 0;
}