/*
 Задача 11.
Напишете програма, в която се въвеждат пореден номер, име, фамилия, възраст на участници в маратон. 
Изискването е за името и фамилията да не се използват масиви с фиксирана дължина. 
След като въвеждането завърши, изведете списък с участниците.

Тази задача е за структури (особенно за класове с полиморфизъм в С++) и би била елементарна с тях. 
Опита по-долу е да се използват само пойнтери, които да се движат в синхрон (без структури).

NOT READY YET
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EnterParticipant (char **Participants, int *Size);
void IncreaseDB (char **Participants, int *Size);
void PrintDB (char **Participants, int *Size);

int main(){
 int DBEntries = 2;
 int *Size = &DBEntries;
 char Answer = 'y';

 char **Participants = calloc(DBEntries, sizeof *Participants);
 for (int i = 0; i<DBEntries; i++){
        Participants[i] = calloc(3, sizeof *(Participants[i]));
    }

 do{
     EnterParticipant (Participants, Size);
     printf("Do you want to add further participants? (Press y for yes, anything else for no)\n");
     scanf(" %c", &Answer);
    } while(Answer=='y');

    PrintDB(Participants, Size);

    free(Participants);
}

void EnterParticipant (char **Participants, int *Size){
    static int i = 0;
    for(int i=0; i < *Size; i++){
        printf("Please enter the Participant Name: \n");
        scanf("%s", &Participants[i][0]);
        printf("Please enter the Participant Surname: \n");
        scanf("%s", &Participants[i][1]);
        printf("Please enter the Participant Age: \n");
        scanf("%d", &Participants[i][2]);
            /*if(i == (*Size-2)){
                *Size += *Size;
                IncreaseDB(Participants, Size);
            }*/
        }
    }

void IncreaseDB (char **Participants, int *Size){
    
}
void PrintDB (char **Participants, int *Size){
    for(int i=0; i<*Size; i++){
        for(int j=0; j<=3; j++){
            printf("%c ", Participants[i][j]);
        }
        printf("\n");
    }
}


/*

int ****Participants [10]      [30]    [30]            [1];
            por. Nr.   Ime     familia          Age
    
Particvipants [malloc]  [malloc] [malloc]      [1]
                [10]     [30]     [30]          [1]
                [realloc] [reLLOC] [RE3ALLOC]    [1]

*/