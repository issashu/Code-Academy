/*
 Задача 14.
Напишете тип за дата, използвайки битови полета. Направете функция, която извежда дата, 
използвайки новия тип. Направете функция, която валидира датата.
*/
#include <stdio.h>
#include <stdint.h>

typedef struct date{
    int32_t Day:5;
    int32_t Month:4;
    int32_t Year:12;
}calendar;

int main(){
    calendar Data;
    int32_t Year = 0;
    int32_t 
    printf("Please enter an year (1900 - 2021):\n");
    scanf("%d", Data.Year);
    printf("Now please enter a month (1-12):\n");
    scanf("%d", Data.Month);



}