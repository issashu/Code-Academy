/*
Задача 8.Дефинирайте едномерен масив int с 10 елемента = {100,90,80,70,60,50,40,30,20,10} 
Дефинирайте пойнтер, който ще сочи към масива.
Достъпете 3 тия елемент от масива и му задайте стойност 5. 
Достъпете 4 тия елемент и му задайте стойност 33. 
Достъпете 5 тия елемент и го намалете със 7.
Достъпете 7 мия елемент и го увеличете с 10.
Достъпете 10 тия елемент и го умножете по 3.
Изпишете го по двата възможни начина и закоментирайте единия. 
Принтирайте на екрана всички елементи на масива.
*/

#include <stdio.h>

void ModifyArray(int *PointyArray);

int main(){
    int Array [10] = {100,90,80,70,60,50,40,30,20,10};
    int *PointyArray = Array;

    printf("Original array is:\n");
    for(int i =0; i< 10; i++){
        printf("%d ", Array[i]);
    }

    ModifyArray(PointyArray);

    printf("\nModified array is:\n");
    for(int i =0; i< 10; i++){
        printf("%d ", *(PointyArray+i));
    /*
    for(int i =0; i< 10; i++){
        printf("%d ", Array[i]);
    */
    }
}

void ModifyArray(int *PointyArray){
    *(PointyArray+2) = 5;
    *(PointyArray+3) = 33;
    *(PointyArray+4) -= 7;
    *(PointyArray+6) += 10;
    *(PointyArray+9) *= 3;
}