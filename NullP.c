/*
Задача 17: Кое е по добре да купите: А броя дини от сорт мелон с диаметър Х сантиметра
и дебелина на кората D сантиметър или В броя дини с диаметър У сантиметра и
същата дебелина на кората D2? Създайте структура диня с два елемента -
диаметър и дебелина на кората заделете динамично с malloc() за масив от А на
брой дини от сорт мелон и попълнете данните за диаметър между 15 и 140 см с
функцията rand(), за всяка една диня в масива и дебелина на кората между 0.5 и
3.5 см. Създайте структура диня с два елемента - диаметър и дебелина на кората
заделете динамично с malloc() за масив от В на брой дини от сорт пъмпкин и
попълнете данните за диаметър между 35 и 95 см с функцията rand(), за всяка
една диня в масива и дебелина на кората между 0.3 и 0.9 см. Намерете средната
големина на динята и средната дебелина на кората и ги съпоставете с тези от
втория масив. Изведете на екрана купчината от кой сорт е по добре да се купи.
Изход:
По-добре е да се купят ... дини с диаметър ... сантиметра и кора с дебелина D
см вместо ... дини с диаметър ... см и дебелина на кората D1 см.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BroiDini 3

typedef struct{
    float Diametar;
    float Kora;
}dinia;

float randomize(int lower, int upper);
float average(dinia *Ptr);

int main(){
    srand(time(0));
    float vutreshnostA=0.0;
    float vutreshnostB=0.0;
    int upper = 35;
    int lower = 5;
    int count = 3;

    dinia *A = malloc(BroiDini*sizeof(dinia));
    dinia *B = malloc(BroiDini*sizeof(dinia));

    for (int i=0 ; i<BroiDini; i++){
        A[i].Diametar = (float) randomize (15, 140);
        B[i].Diametar = (float) randomize (35, 95);

        A[i].Kora = (float) randomize (5, 35)/10;
        B[i].Kora = (float) randomize (3, 9)/10;
    }

    //A=NULL;
    vutreshnostA=average(A);
    vutreshnostB=average(B);
    if(vutreshnostA>vutreshnostB){
        printf("Its better to buy melon from sort A with average ripe interior of %.1f cm\n",vutreshnostA);
    }
    else if (vutreshnostA<vutreshnostB){
        printf("Its better to buy melon from sort B with average ripe interior of %.1f cm\n",vutreshnostB);
    }
    else {
        printf("They are equal\n");
    }

    free(A);
    free(B);
    return 0;
}

float randomize(int lower, int upper){
    float num = (rand() % (upper - lower + 1)) + lower;

    return num;
}

float average(dinia *Ptr){
    float Average = 0.00;
    float Suma = 0.00;
    float Average1 = 0.00;
    float Suma1 = 0.00;

    for (int i =0; i<BroiDini; i++){
        Suma += Ptr[i].Kora;
    }

    Average = Suma/BroiDini;

    for (int i =0; i<BroiDini; i++){
        Suma1 += Ptr[i].Diametar;
    }

    Average1 = Suma1/BroiDini;

    return Average1-Average;
}

/*
clang -fsanitize=null NullP.c
*/