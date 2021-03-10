/*
Пренапишете задачи 14 и 15 от лекция 22 за Потребителски 
типове като пуснете двете екзета в pipe:
maraton.exe | sort.exe

Задача 14 Напишете програма, в която се въвеждат пореден 
номер, име, фамилия, възраст на участници в маратон. 
Изискването е, за името и фамилията, да не се използват масиви 
с фиксирана дължина. След като въвеждането завърши, 
изведете списък с участниците.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define listSize 5

const char* PARTICIPANT_FORMAT_OUT = "(%d, %s, %s, %d)\n";
const char* PARTICIPANT_FORMAT_IN = "(%d, %[^,], %[^,], %d)\n";

typedef struct participant{   
 unsigned numOfPart;
 char *firstName;
 char *secondName;
 int age;
}participant;

void addPart(participant* participant0);
void Sort(participant* participant0,int count);

int main(){
 participant *participant0;
 participant0=malloc(listSize*sizeof(participant));
 addPart(participant0);
 free(participant0);
}

void addPart(participant* participant0){
    int i;
    int count=0;
    char choice='1';
    for(i=0;i<5;i++){
        participant0[i].firstName=malloc(20);
        participant0[i].secondName=malloc(20);
        scanf(PARTICIPANT_FORMAT_IN, &participant0[i].numOfPart, participant0[i].firstName, participant0[i].secondName, &participant0[i].age);
        count++;
    }
    Sort(participant0,count);
    printf("Receiving participant data... \n");
    for (int i=0; i<count;i++){
        printf(PARTICIPANT_FORMAT_OUT, participant0[i].numOfPart, participant0[i].firstName, participant0[i].secondName, participant0[i].age);
    }
}

void Sort(participant* participant0,int count){
    char *temp = NULL;
    int Number, i, j;

    for(i = 0; i < count-1; i++){
        for(j = i + 1; j < count; j++){

            if(strncmp(participant0[i].firstName, participant0[j].firstName, 4) > 0){
                
                temp = participant0[j].firstName;
                participant0[j].firstName = participant0[i].firstName;
                participant0[i].firstName = temp;

                temp = participant0[j].secondName;
                participant0[j].secondName = participant0[i].secondName;
                participant0[i].secondName = temp;

                temp = participant0[j].numOfPart;
                participant0[j].numOfPart = participant0[i].numOfPart;
                participant0[i].numOfPart = temp;

                temp = participant0[j].age;
                participant0[j].age = participant0[i].age;
                participant0[i].age= temp;
            }
        }
    }
}