/*
Задача 20. Дефинирайте стринг „I am a poor programmer”. Заменете през пойнтер “poor” с “great”.
*/

#include <stdio.h>
#include <string.h>

int main(){
    char array[] = "I am a poor programmer";
    char arraysubstitute [] = "great";

    char *Pointy = &array[0];
    char *SubPointy = strstr(array, "poor");
    char *PointoPlace = arraysubstitute;
    int Counter = 0;
    if (SubPointy==NULL){
        printf("String not found! Error! Eroor! Waaaah!");
    }
    else{
        while(*SubPointy && *PointoPlace!='\0'){
            *SubPointy = *PointoPlace;
            *SubPointy++;
            *PointoPlace++;
            Counter++;
        }
    }
    printf("%s", Pointy);
}