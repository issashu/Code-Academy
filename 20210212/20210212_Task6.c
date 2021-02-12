/*
 Задача 6.
Заделете динамично с malloc памет за char* buffer с размер size = 2,
въвеждайте символи от конзолата с getchar() ги четете, записвайте ги в буфера. 
Увеличавайте размера на буфера преди да се препълни с realloc().
Прекъснете цикъла с Ctrl + Z. Принтирайте буфера и освободете паметта.

Направена е със scanf. Не ми се получава с getchar() и прекъсване (CTRL+C просто прекъсва всичко). 
Заради това съм сложил автоматично прекъсване, когато увеличим бъфера три поредни пъти.

Пак имам бъг, че брой enter като юн , но не съм сложил сега проверка да го игнорира.

Логиката за увеличаване на отделената памет в хийп е обаче същата. Като се запълни, реалокира пойнтера на ново
място в паметта и така 3 поредни пъти.
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
        for(i; i<max; i++){
            scanf("%c", &Pointy[i]);
            /*DEBUGGER:
            Pointy[i] = 'q';
            */
            //1 chas!!!!!!!!! debugvah, dokato se usetia, che sam pisal =, a ne == ....
            if (i == max - 1) {
            Pointy = realloc (Pointy, max+2);
                if (!Pointy) {
                    printf ("Realloc failed!!!\n");
                }
            max += 2;
            trigger++;
            }
            if(trigger==3){
                Pointy[i+1]='\0';
                break;
            }
                
        }
    }
    for (int i=0; Pointy[i]!='\0';i++){
        printf("%c", Pointy[i]);
    }
}