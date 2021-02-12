/*
 Задача 6.
Заделете динамично с malloc памет за char* buffer с размер size = 2,
въвеждайте символи от конзолата с getchar() ги четете, записвайте ги в буфера. 
Увеличавайте размера на буфера преди да се препълни с realloc().
Прекъснете цикъла с Ctrl + Z. Принтирайте буфера и освободете паметта.

Направена е със scanf. Не ми се получава с getchar() и прекъсване (CTRL+C просто прекъсва всичко). 
Заради това съм сложил автоматично прекъсване, когато увеличим бъфера три поредни пъти.

Логиката за увеличаване на отделената памет в хийп е обаче същата.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 0;
    int max = 2;
    int trigger = 0;
    printf("Please enter the values for Pointy:\n");
    char *Pointy = malloc(max);
    while(Pointy && trigger < 3){
        for(int i=0; i<max; i++){
            scanf("%c", &Pointy[i]);
            if (i = max) {
            void *temp = realloc (Pointy, max + 2);
                if (!temp) {
                    printf ("Realloc failed!!!\n");
                }
            Pointy = temp;
            max += 2;
            trigger++;
            }
            if(trigger==3)
                break;
        }
    }
}