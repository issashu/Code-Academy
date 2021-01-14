#include <stdio.h>

int main()
{
    float TomatoPrice =4.50;
    float fTomatoWeight=0.00;
    float FlourPrice = 1.80;
    float fFlourWeight=0.00;
    float YoghurtPrice = 0.50;
    int YoghurtBoxes=0;
    float IceCreamPrice = 0.60;
    int IceCreamCorns=0;
    float BonbonPrice = 1.50;
    float fBonBonWeight=0.00;
    float LollipopPrice = 0.15;
    int LollipopPierces =0;

    printf("Welcome to Unicorn COOP. Today we offer fresh Tomatoes, Flour, Yoghurt, Ice Cream, Bobons and Lollipops!\n");
    printf("How many kg of Tomatoes does it wants, Precious?\n");
    scanf("%f", &fTomatoWeight);
    printf("That will be total of %.2f BGN", (fTomatoWeight*TomatoPrice));

}