#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tm Time_t;
int AddTime(Time_t *Period);

int main(){
    Time_t Period = (Time_t)malloc(sizeof(Time_t));
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
