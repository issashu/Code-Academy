/*
 Задача 6.
Опишете времето в структура: часове:минути:секунди като структура tagTMyTime. 
Използвайки тази структура, дефинирайте следните функции: добавяне на секунди, 
добавяне на минути. Добавяне на часове към дадена променлива от тип struct tagTMyTime. 
Напишете следните функции: връщане на броя секунди за дадена променлива от въведения тип 
и обратна функция от секундите да се генерира променлива tagTMyTime. Напишете две функции, 
които изваждат и събират две променливи от тип struct tagMyTime и връщат променлива от същия 
тип. Използвайте тези функции, за да се уверите, че работят коректно.

struct tm {
   int tm_sec;            seconds,  range 0 to 59          
   int tm_min;            minutes, range 0 to 59           
   int tm_hour;           hours, range 0 to 23             
   int tm_mday;           day of the month, range 1 to 31  
   int tm_mon;            month, range 0 to 11             
   int tm_year;           The number of years since 1900   
   int tm_wday;           day of the week, range 0 to 6    
   int tm_yday;           day in the year, range 0 to 365  
   int tm_isdst;          daylight saving time             
};
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tm Time_t;
int AddTime(Time_t *Period);

int main(){
    Time_t Period ={.tm_hour = 0, .tm_min = 0, .tm_sec = 0};
    Time_t *pPeriod = &Period;
    printf("Current time is: %d:%d:%d\n", Period.tm_hour, Period.tm_min, Period.tm_sec);
    AddTime(pPeriod);
    printf("Jump set to time is: %d:%d:%d", Period.tm_hour, Period.tm_min, Period.tm_sec);

}

int AddTime(Time_t *Period){
    /*1h=60m=3600s*/
    int TimeFrame = 10;
    printf("Please enter a value to add as time period:\n");
    scanf("%d", &TimeFrame);
    if(TimeFrame < 60){
        printf("Adding %d seconds to time!\n", TimeFrame);
        Period->tm_sec+=TimeFrame;
    }
    else if (TimeFrame<3600){
        printf("Adding %d minutes to time!\n", (TimeFrame/60));
        Period->tm_min+=(TimeFrame/60);
    }
    else if(TimeFrame<86400){
        printf("Adding %d hours to time!\n", (TimeFrame/3600));
        Period->tm_hour+=(TimeFrame/3600);
    }
    else{
        printf("Value entered too big!\n");
        return 1;
    }
}
