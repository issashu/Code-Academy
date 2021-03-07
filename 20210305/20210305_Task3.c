/*
Задача 3. С увеличаване на надморската височина температурата намалява с 
около 0,5ºC на всеки 100м. Нека приемем, че атмосферното налягане е нормално. 
Ако се знае температурата (ХºC) на хижа Вихрен (1950 метра над морското 
равнище), да се изчисли каква е температурата на връх Вихрен (2918 метра над 
морското равнище). Ако се знае температурата (УºC) на връх Вихрен, да се изчисли 
каква е температурата на хижа Вихрен. 
Изход 1:
Ако атмосферното налягане е нормално и температурата на хижа Вихрен (1950м 
н.м.р.) е ... ºC , то температурата на връх Вихрен (2918м н.м.р.) е ... ºC.
Изход 2:
Ако атмосферното налягане е нормално и температурата на връх Вихрен (2918м 
н.м.р.) е ... ºC , то температурата на хижа Вихрен (1950м н.м.р.) е ... ºC.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char Location[40];
    int Temperature;
    bool OnFlag;
    int Altitude;
} t_station;

t_station* Setter(t_station* Cabin, t_station* Peek);
void Destroy(t_station* Cabin, t_station* Peek);
void CalculateTemperature(t_station* Cabin, t_station* Peek);

int main(){
    t_station* CabinWoods = malloc(sizeof(t_station));
    t_station* PeekVihren = malloc(sizeof(t_station));
    Setter(CabinWoods, PeekVihren);
    CalculateTemperature(CabinWoods, PeekVihren);
    Destroy(CabinWoods, PeekVihren);
}

t_station* Setter(t_station* Cabin, t_station* Peek){
    short Location;
    short Temperature;
    strcpy(Cabin->Location, "Vihren Cabin");
    strcpy(Peek->Location, "Vihren Peek");
    Cabin->Temperature = 0;
    Peek->Temperature = 0;
    Cabin->Altitude = 1950;
    Peek->Altitude = 2918;
    
location:
    printf("Where are you currently located?\n 1.Cabin Vihren\n 2.Peek Vihren\n");
    scanf("%hd", &Location);
    printf("And what is the current temperature at the location?\n");
    scanf("%hd", &Temperature);

    if(Location == 1){
        Cabin->Temperature = Temperature;
        Cabin->OnFlag = 1;
        Peek->OnFlag = 0;
    }
    else if(Location == 2){
        Peek->Temperature = Temperature;
        Peek->OnFlag = 1;
        Cabin->OnFlag = 0;
    }
    else{
        printf("\n\nWrong location entered. Please select 1 or 2!\n");
        goto location;
    }
}

void Destroy(t_station* Cabin, t_station* Peek){
    free(Cabin);
    free(Peek);
}

void CalculateTemperature(t_station* Cabin, t_station* Peek){
    float AltDif = 0;
    float TempMod = 0.5;

    AltDif = Peek->Altitude - Cabin->Altitude;

/* 248 below is the ascii code for ° */
    if(Cabin->OnFlag == 1){
        Peek->Temperature = Cabin->Temperature - ((AltDif/100)*TempMod);
        printf("The temperature at %s currently (based on altitude difference) should be about %d%cC.\n", Peek->Location, Peek->Temperature, 248);
    }
    else if (Peek->OnFlag == 1){
        Cabin->Temperature = Peek->Temperature + ((AltDif/100)*TempMod);
        printf("The temperature at %s currently (based on altitude difference) should be about %d%cC.\n", Cabin->Location, Cabin->Temperature, 248);
    }
}