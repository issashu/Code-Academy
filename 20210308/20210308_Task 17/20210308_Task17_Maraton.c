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

//Defined a default format for printing/reading/serialization to files
//[^,] is equal to read all characters[] except ^ the comma ,
const char* PARTICIPANT_FORMAT_OUT = "(%d, %s, %s, %d)\n";
const char* PARTICIPANT_FORMAT_IN = "(%d, %[^,], %[^,], %d)\n";

typedef struct participant{
    
 unsigned numOfPart;
 char firstName[20];
 char secondName[20];
 int age;
}participant;

void addPart(participant* participant0);

int main(){
 participant *participant0;
 participant0=malloc(listSize*sizeof(participant));
 addPart(participant0);
 free(participant0);
}

void addPart(participant* participant0){
    FILE *FilePointer = NULL;
    //rt means read text and specifies we will be getting strings
    //SEEK_SET below means first position in the file
    FilePointer = fopen("Task6.txt", "rt");
    int i;
    int count=0;
    char choice='1';
    for(i=0;choice!='0';i++){
        printf("Reading Participant data... \n");
        fscanf(FilePointer, PARTICIPANT_FORMAT_IN, &participant0[i].numOfPart, participant0[i].firstName, participant0[i].secondName, &participant0[i].age);
        count++;
        printf("Do you have another participant to add?\nPress 1 to enter new participant or 0 to print a list of participants.\n");
        scanf(" %c",&choice); 
    }

    for (i=0;i<count;i++){
        fprintf(stdout, PARTICIPANT_FORMAT_OUT, participant0[i].numOfPart, participant0[i].firstName, participant0[i].secondName, participant0[i].age);
    }
    fclose(FilePointer);
}

void myFree(participant* participant0){
    for(int i=0;i<listSize;i++){
        free(participant0[i].firstName);
        free(participant0[i].secondName);
    }
}