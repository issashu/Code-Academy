/*
 Задача 14.
Напишете тип за дата, използвайки битови полета. Направете функция, която извежда дата, 
използвайки новия тип. Направете функция, която валидира датата.

https://en.cppreference.com/w/c/types/integer

Реших да пробвам изваждане на битове от число, ползвайки бит фийлдс, като всичката информация
я запазвам в юниън със структура в едно, за да пестим рам място.
Подход напрограмата:
1. Питаме юзъра да въведе година, месец и ден.
2. Намираме дължината в битове (1 и 0) на всяко число. В случая са фиксирани:
    - 1-31 е 5 бита
    - 1-12 е 4 бита
    - 1900-2021 е 12 бита
3. Шифтваме на ляво деня, добавяме месеца 
4. Шифтваме цялото на ляво и добавяме годината.
5. Така полученото число би трябвало да влиза в 32 битов интиджър.
6. С бит полета си вадим бройката необходими битове, за да извадим датата от кодировката

|____5-Day______|___4-Month____|________12-Year_________|

Би трябвало на края да имаме същата дата като въведената от потребителя.

Задачата е правена съвсем на бързо и не е много елегантна.
*/

#include <stdio.h>
#include <stdint.h>

u_int8_t BitwiseLenght(u_int32_t number);
u_int32_t ConvertDate(u_int32_t Day, u_int32_t Month, u_int32_t Year);

union calendar{
    u_int32_t BinaryDate;
    struct{
        u_int32_t Year  :12;
        u_int32_t Month :4;
        u_int32_t Day   :5;
    } DateFields;
};

int main(){
    union calendar CalendarDate;
    u_int32_t Year = 0;
    u_int32_t Month = 0;
    u_int32_t Day = 0;
    printf("Please enter an year (1900 - 2021):\n");
    do{
        scanf("%d", &Year);
    }while(Year <1900 || Year >2021);
    
    printf("Now please enter a month (1-12):\n");
    do{
        scanf("%d", &Month);
    } while( Month<1 || Month>12);
    
    if(Year%400 == 0 && Month==2){
        printf("Now please enter a day (1-29):\n");
        do{
            scanf("%d", &Day);
        } while( Day<1 || Day>29);    
    }
    else if(Year%400 != 0 && Month==2){
         printf("Now please enter a day (1-28):\n");
         do{
            scanf("%d", &Day);
        } while( Day<1 || Day>28);
    }
    else{
        printf("Now please enter a day (1-31):\n");
        do{
            scanf("%d", &Day);
        } while( Day<1 || Day>31);
    }
    
    printf("DEBUG: %d", sizeof(CalendarDate));

    CalendarDate.BinaryDate = ConvertDate(Day, Month, Year);

    printf("The date you entered is:\n");
    printf("%d.%d.%d", CalendarDate.DateFields.Year, CalendarDate.DateFields.Month, CalendarDate.DateFields.Day);
}

u_int32_t ConvertDate(u_int32_t Day, u_int32_t Month, u_int32_t Year){
    u_int8_t DayShift = 5;
    u_int8_t MonthShift = 4;
    u_int8_t YearShift = 12;
    u_int32_t Result = 0;

    Result = (((Day<<MonthShift)+Month)<<YearShift)+Year;

    printf("DEBUG: %d\n", Result);
    return Result;
}