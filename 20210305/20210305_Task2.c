/*
Задача 2 Пощенските такси на дадена куриерска фирма се определят според 
тежестта на пратките (с точност до цял грам) и обема, както е показано в таблицата. 
Тегло (с точност до 1 грам) Такса до 20 г 0,46 лева; 21-50 г 0,69 лева; 51-100 г
1,02 лева; 101-200 г 1,75 лева; 201-350 г 2,13 лева; 351-500 г 2,44 лева; 501-
1000 г 3,20 лева; 1001-2000 г 4,27 лева; 2001-3000 г 5,03 лева;
Обем: до 10см + 0,01лв; 10- 50 см + 0,11 лева, 50-100 см + 0,22лв, 100-150см + 0,33лв, 150-
250см +0,56лв, 250-400см+1.50лв, 400-500см+3,11лв, 500-600см+4,89лв, над 600см+ 5.79лв
Потребителя се пита за броя на пратките пратки след което теглото на всяка пратка и обема и. 
Определете според пощенските такси в тази куриерска фирма как по-евтино да изпрати своите 
пратки като една или да ги изпрати като отделни пратки.
Изход 1:
За пратки с тегло ... грама обем ... и ... грама ...обем е по-добре да бъдат изпратени заедно. В 
този случай изпращането ще струва ... лева.
Изход 2:
За пратки с тегло ... грама обем ... и ... грама ...обем е по-добре да бъдат изпратени заедно. В 
този случай изпращането ще струва ... лева.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    short Weight;
    short Height;
    short Tarrif;
}t_usluga;

t_usluga* Setter(t_usluga* Struct, short* Packages);
void Destroyer(t_usluga* Struct);

int main(){
    short NrPackages = 0;
    printf("Welcome to Barzite Delivery Service!\nThe first fully automated drone delivery service. We will deliver your packages shaken, not stirred.\n");
    printf("How many packages do you need to ship: ");
    scanf("%hd", &NrPackages); 
    t_usluga Shipment[NrPackages];

}

t_usluga* Setter(t_usluga* Struct, short* Packages){
    Struct = calloc(Packages, Sizeof(t_usluga)); 

    printf("How much does the package Weight (in gramms)?\n");
    scanf("%hd", &Struct->Weight);
    printf("What is the package Height (in cm)?\n");
    scanf("%hd", &Struct->Height);
    
    return Struct;
}

void Destroyer(t_usluga* Struct){
    free(Struct);
}