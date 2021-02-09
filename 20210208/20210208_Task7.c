/*
7. Напишете един глобален масив, който съдържа на всяка позиция броя на дните от 
месеца. Направете функция, която на която се подават като аргументи година, месец 
и ден. На база на това функцията трябва да върне поредния ден от годината. 
Например 1 март е 60 тия ден от годината.
*/
#include <stdio.h>

int DaytheYear (int *s, int year, int month, int day);
int MonthsDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int year = 1900;
    int month = 1;
    int day = 1;

    printf("Please enter a desired date as follows:\n");
    do{
        printf("Year: ");
        scanf("%d", &year);
    }while(year%100==0);
    
    printf("Month: ");
    scanf("%d", &month);
    printf("Day: ");
    scanf("%d", &day);
    printf("\n%d\n", DaytheYear(MonthsDays, year, month, day));

}

int DaytheYear (int *s, int year, int month, int day){
    int Sum_days=0;
    //Decrease month by 1 to consider 0 element index
    month-=1;
    if (year%4!=0){
        s[1] = 28;
    }
    //Add the days of full months
    for (int i=0; i<month; i++){
        Sum_days += s[i];
    }
    //Add remaining days
    Sum_days += day;

    return Sum_days;
}