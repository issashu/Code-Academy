/*
Задача 4. Даден е едномерен масив с N елемента (вие изберете стойност на N),
напишете функция, която изчислява средната стойност на елементите в масива, 
като я връща като double float.
*/

#include <stdio.h>

double Average(int *s);

int main(){
    int AverageArray[3]={1, 2, 34};
    printf("Please enter the elements of the array (total of 3):\n");
    for (int i=0;i<3;i++)
        scanf("%d", &AverageArray[i]);
    printf("The average value of the array elements is: %.2lf\n", Average(AverageArray));

}

double Average(int *s){
    int SumOfElements =0;
    double Result =0.00;
    short Counter = 0;

    for(int i=0; i<3; i++){
        SumOfElements+=s[i];
        Counter++;
    }

    Result = SumOfElements/Counter;

    return Result;
}