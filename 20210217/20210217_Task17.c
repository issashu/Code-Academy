/*
 Задача 17*.
Имаме 2 сортирани масиви А и В с различна размерност k и l и произволни int числа.
Образувайте масив С, образуван от смесването на А и В, така че С да съдържа елементите 
на А и В, но да е подреден и да не се налага да го сортираме отново.

Програмата си прави два масива на произволен принцип от по 88 елемента между 1 и 10. 
Може да се махне тоъи лимит на линия 46

Повечето функции могат да се изнесат в .h и отделни .с и да се използват после
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillArray(int *array, int size);
//Ne raboti s vanshna funktzia...printiram v main()
//void Printer(int array[], int size);
void SortedArrayMerge(int *array1, int *array2, int size1, int size2, int *array3);
void SortArray(int *array, int size);

int main()
{
    int Size1 = 10;
    int Size2 = 10;
    int Size3 = 10;
    int *Array1 = NULL;
    int *Array2 = NULL;
    int *Array3 = NULL;

    printf("Please enter a size for the first array:\n");
    scanf("%d", &Size1);
    printf("Please enter a size for the second array:\n");
    scanf("%d", &Size2);
    Size3 = Size1 + Size2;

    Array1 = (int*) calloc(Size1, sizeof(int));
    Array2 = (int*) calloc(Size2, sizeof(int));
    Array3 = (int*) calloc(Size3, sizeof(int));

    void (*Setter)(int*, int) = FillArray;
    void (*MergeArrays)(int*, int*, int, int, int*) = SortedArrayMerge;
    void(*SortAnArray)(int*, int) = SortArray;
    
    Setter(Array1, Size1);
    Setter(Array2, Size2);
    SortAnArray(Array1, Size1);
    SortAnArray(Array2, Size2);
    MergeArrays(Array1, Array2, Size1, Size2, Array3);

    printf("First array:\n");
    for (int i = 0; i<Size1; i++){
        printf("%d ", Array1[i]);
    }
    printf("\n");
    printf("Second array: \n");
    for (int i = 0; i<Size2; i++){
        printf("%d ", Array2[i]);
    }
    printf("\n");
    printf("Array after merging\n");
    for (int i = 0; i<Size3; i++){
        printf("%d ", Array3[i]);
    }
    printf("\n");
}

void FillArray(int *array, int size){
    srand(time(0));
    for (int i=0; i< size; i++){
        *(array+i) = rand()%10;
    }
}

void SortedArrayMerge(int *array1, int *array2, int size1, int size2, int *array3){
    int i = 0; 
    int j = 0; 
    int k = 0;
 
    while (i<size1 && j <size2){
        if (array1[i] < array2[j]){
            array3[k++] = array1[i++];
        }
        else{
            array3[k++] = array2[j++];
        }
    }
    /* Whatever is left from either array is put back in. No sorting done, since it is assumed to be sorted
       If sorting needed, additional function must be put in place!*/
    while (i < size1){
        array3[k++] = array1[i++];
    }
    while (j < size2){
        array3[k++] = array2[j++];
    }
}

void SortArray(int *array, int size){
    int i, j = 0;
    int tmp = 0;
    
    for (i = 0; i < size; ++i) {
        for (j = i + 1; j < size; ++j){
            if (array[i] > array[j]) {
                tmp =  array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}