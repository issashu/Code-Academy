/*
Задача 3.
Дефинирайте структура с три елемента, които са променливи тип int, char и float.
Елементите да са наименование на продукт, цена и количество.
Задайте стойност на всеки от елементите, както следва: chocolate, 2.50, 50. 
Отпечатайте на екрана.
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct __attribute__((__packed__)){
    char Produkt[50];
    float Tzena;
    uint16_t Kolichestvo;
} smetka;


int main(){
    smetka Shokolad;
    Shokolad.Tzena = 2.50;
    strcpy(Shokolad.Produkt, "shokolad");
    
    printf("Please enter how much %s you want to buy (in grams):\n", Shokolad.Produkt);
    scanf("%d", &Shokolad.Kolichestvo);

    printf("For the %d gramms of %s, the price would be %.2f leva", Shokolad.Kolichestvo, Shokolad.Produkt, (Shokolad.Tzena*(Shokolad.Kolichestvo/100)));
}