/*
Кое е по добре да купите: А броя дини от сорт мелон с диаметър Х сантиметра
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
см вместо ... дини с диаметър ... см и дебелина на кората D1 см
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

struct type{
    int size;
    float peel;
};
float generateRandoms(int lower, int upper);
float watermelons(char *sort,int lowerSize, int upperSize,int lowerPeel, int upperPeel,int number,float *meanSize, float *meanPeel);
void CompareMellons(float meanMellon,float meanPumpkin, float meanSize, float meanSize2, float meanPeel, float meanPeel2);

int main() 
{ 
    srand(time(0));
    int A = rand()%21; /* number ot mellon */
    int B = rand()%21; /* number of pumpkin */
    int lowerX = 15, upperX = 140; /* size of mellon */
    int lowerD = 5, upperD  = 35; /* peel of mellon */
    int lowerY = 35, upperY = 95; /* size of pumpkin */
    int lowerD2 = 3, upperD2  = 9; /* peel of pumpkin */
    float meanSize=0.0, meanPeel = 0.0;
    float meanSize2=0.0, meanPeel2 = 0.0;
    
    float meanMellon = watermelons("mellon",lowerX,upperX,lowerD, upperD, A, &meanSize, &meanPeel);
    float meanPumpkin = watermelons("pumpkin",lowerY,upperY,lowerD2, upperD2, B, &meanSize2, &meanPeel2);
    
    CompareMellons(meanMellon, meanPumpkin, meanSize, meanSize2, meanPeel, meanPeel2);

    return 0; 
}

float generateRandoms(int lower, int upper) /*generate 1 random number in range[low,upper] */
{ 
    float num = (rand() % (upper - lower + 1)) + lower; 
    return num;
} 

float watermelons(char *sort,int lowerSize, int upperSize,int lowerPeel, int upperPeel,int number,float *meanSize, float *meanPeel){
    struct type *psort;
     
    psort = malloc(number*sizeof(struct type));
    printf("\nWaterlemons of sort %s: %d",sort, number);
    for(int i=0;i<number;i++){
        psort[i].size= generateRandoms(lowerSize, upperSize);
        psort[i].peel= (float)generateRandoms(lowerPeel, upperPeel)/10.0;
        *meanSize +=psort[i].size;
        *meanPeel +=psort[i].peel;
        printf("\n{%d ,%f}",psort[i].size, psort[i].peel);
    }
    *meanSize = *meanSize/number;
    printf("\n\nmean size %s = %f",sort, *meanSize);
    *meanPeel = *meanPeel/number;
    printf("\nmean peel %s = %f",sort, *meanPeel);
    printf("\nnumber watermelons %s = %d",sort, number);
    float meanWatermelon = *meanSize - *meanPeel;
    printf("\nmean to eat sort %s = %f\n",sort, meanWatermelon);
    
    return meanWatermelon;
}

void CompareMellons(float meanMellon,float meanPumpkin, float meanSize, float meanSize2, float meanPeel, float meanPeel2){
    if(meanMellon>=meanPumpkin){
        printf("\nIt is better to buy watermelons mellon with diameter X = %f and peel tick D = %f,\
        \nthan waterlemmons pumpkin with diameter Y = %f and peel tick D2 = %f", meanSize, meanPeel, meanSize2, meanPeel2);
    }
    else{
        printf("\nIt is better to buy watermelons pumpkin with diameter Y = %f and peel tick D2 = %f,\
        \nthan waterlemmons mellon with diameter X = %f and peel tick D = %f", meanSize2, meanPeel2, meanSize, meanPeel);
    }
}