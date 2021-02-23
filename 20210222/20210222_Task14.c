/*
 Задача 14.
Напишете тип за дата, използвайки битови полета. Направете функция, която извежда дата, 
използвайки новия тип. Направете функция, която валидира датата.

Реших да пробвам изваждане на битове от число, ползвайки бит фийлдс, като всичката информация
я запазвам в юниън със структура в едно, за да пестим рам място.
Подход напрограмата:
1. Питаме юзъра да въведе година, месец и ден.
2. Намираме дължината в битове (1 и 0) на всяко число.
3. Шифтваме на ляво деня, добавяме месеца 
4. Шифтваме цялото на ляво и добавяме годината.
5. Така полученото число би трябвало да влиза в 32 битов интиджър.
6. С бит полета си вадим бройката необходими битове, за да извадим датата

|____5-Day______|___4-Month____|________12-Year_________|

Би трябвало на края да имаме същата дата като въведената от потребителя.
*/

#include <stdio.h>
#include <stdint.h>

u_int8_t BitwiseLenght(int32_t number);
int32_t ConvertDate(int32_t Day, int32_t Month, int32_t Year);

union calendar{
    int32_t BinaryDate;
    
    struct{
        int32_t Year  :12;
        int32_t Month :4;
        int32_t Day   :5;
    } DateFields;
};

int main(){
    union calendar CalendarDate;
    int32_t Year = 0;
    int32_t Month = 0;
    int32_t Day = 0;
    printf("Please enter an year (1900 - 2021):\n");
    scanf("%d", &Year);
    printf("Now please enter a month (1-12):\n");
    scanf("%d", &Month);
    printf("Now please enter a day (1-31):\n");
    scanf("%d", &Day);

    CalendarDate.BinaryDate = ConvertDate(Day, Month, Year);

    printf("The date you entered is:\n");
    printf("%d.%d.%d", CalendarDate.DateFields.Year, CalendarDate.DateFields.Month, CalendarDate.DateFields.Day);
}

int32_t ConvertDate(int32_t Day, int32_t Month, int32_t Year){
    u_int8_t DayShift = 0;
    u_int8_t MonthShift = 0;
    u_int8_t YearShift = 0;
    int32_t Result = 0;

    DayShift = BitwiseLenght(Day);
    MonthShift = BitwiseLenght(Month);
    YearShift = BitwiseLenght (Year);

    Result = (((Day<<MonthShift)+Month)<<YearShift)+Year;

    printf("DEBUG: %d\n", Result);
    return Result;
}

u_int8_t BitwiseLenght(int32_t number){
    u_int8_t counter = 0;
    while (number){
        counter++;
        number >>= 1;
    }

    return counter;
}