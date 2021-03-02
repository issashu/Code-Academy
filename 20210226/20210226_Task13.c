/*
Опишете времето в структура: часове:минути:секунди като структура tagTMyTime.
Използвайки тази структура, дефинирайте следните функции: добавяне на секунди,
добавяне на минути. Добавяне на часове към дадена променлива от тип struct
tagTMyTime. Напишете следните функции: връщане на броя секунди за дадена
променлива от въведения тип и обратна функция от секундите да се генерира
променлива tagTMyTime. Напишете две функции, които изваждат и събират две
променливи от тип struct tagMyTime и връщат променлива от същия тип.
Използвайте тези функции, за да се уверите, че работят коректно.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
}tagTMyTime;

void checkTime(tagTMyTime *time);
void addSeconds(tagTMyTime* time,int seconds);
void addMinutes(tagTMyTime *time,int minutes);
void addHours(tagTMyTime *time,int hours);
void printTime(tagTMyTime *time);
tagTMyTime add(tagTMyTime *time,tagTMyTime *time1,tagTMyTime *time2);

int main(){
    tagTMyTime *clock=NULL;
    tagTMyTime *clock1=NULL;
    clock=(tagTMyTime*)malloc(sizeof(tagTMyTime));
    clock1=(tagTMyTime*)malloc(sizeof(tagTMyTime));
    clock->hours=20;
    clock->minutes=32;
    clock->seconds=34;
    addSeconds(clock,42);
    printTime(clock);
    addMinutes(clock,62);
    printTime(clock);
    addHours(clock,2);
    printTime(clock);
    clock1->hours=15;
    clock1->minutes=21;
    clock1->seconds=35;
    tagTMyTime *clock2=NULL;
    clock2=(tagTMyTime*)malloc(sizeof(tagTMyTime));
    
    add(clock, clock1,clock2);
    printTime(clock2);
    free(clock);
    free(clock1);
    free(clock2);
}

void checkTime(tagTMyTime *time){
    if(time->seconds>59){
        time->minutes=time->seconds/60+time->minutes;
        time->seconds=time->seconds%60;
        }
    if(time->minutes>59){
            time->hours=time->minutes/60+time->hours;
            time->minutes=time->minutes%60;
        }
    if (time->hours >23){   
        if(time->hours==24){
        time->hours=0;
    }
    else{    
        time->hours = abs(time->hours-24);
        }
    }
}

void addSeconds(tagTMyTime* time,int seconds){
    time->seconds+=seconds;
    checkTime(time);
}

void addMinutes(tagTMyTime *time,int minutes){
    time->minutes+=minutes;
    checkTime(time);
}

void addHours(tagTMyTime *time,int hours){
    time->hours+=hours;
    checkTime(time);

}

void printTime(tagTMyTime *time){
    printf("%02d:%02d:%02d\n", time->hours, time->minutes, time->seconds);
}

tagTMyTime add(tagTMyTime *time,tagTMyTime *time1,tagTMyTime *time2){
    time2->seconds=time->seconds+time1->seconds;
    time2->minutes=time->minutes+time1->minutes;
    time2->hours=time->hours+time1->hours;
    checkTime(time2);
}