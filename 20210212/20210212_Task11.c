/*
 Задача 11.
Напишете програма, в която се въвеждат пореден номер, име, фамилия, възраст на участници в маратон. 
Изискването е за името и фамилията да не се използват масиви с фиксирана дължина. 
След като въвеждането завърши, изведете списък с участниците.

Тази задача е за структури (особенно за класове с полиморфизъм в С++) и би била елементарна с тях. 
Опита по-долу е да се използват само 2D пойнтери, които да се движат в синхрон (без структури).

NOT READY YET
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EnterParticipant (char **Participants, int *Size, int *NameLength);
void IncreaseDB (char **Participants, int *Size, int *NameLength);
void PrintDB (char **Participants, int *Size, int *NameLength);

int main(){
 int DBEntries = 2;
 int StrLen = 30;
 int NrColumns = 3;
 int *DBSize = &DBEntries;
 int *NameLength = &StrLen;
 char **Participants = calloc(DBEntries, sizeof *Participants);
 for (int i = 0; i<DBEntries; i++){
        Participants[i] = calloc(NrColumns, StrLen * sizeof(char));
    }
    EnterParticipant (Participants, DBSize, NameLength);
    PrintDB(Participants, DBSize, NameLength);
    free(Participants);
}

void EnterParticipant (char **Participants, int *Size, int *NameLength){
    static int i = 0;
    char Answer ='y';
    do{
        printf("Please enter the Participant Name: \n");
        fgets(&Participants[i][0], *NameLength, stdin);
        printf("Please enter the Participant Surname: \n");
        fgets(&Participants[i][1], *NameLength, stdin);
        printf("Please enter the Participant Age: \n");
        fgets(&Participants[i][2], *NameLength, stdin);
        i++;
            if(i == (*Size-2)){
                *Size += *Size;
                IncreaseDB(Participants, Size, NameLength);
            }
        printf("Do you want to add further participants? (Press y for yes, anything else for no)\n");
        Answer = getchar();
    } while(Answer=='y');
}

void IncreaseDB (char **Participants, int *Size, int *NameLength){
    Participants = realloc(Participants, *Size);
}
void PrintDB (char **Participants, int *Size, int *NameLength){
    for(int i=0; i<*Size; i++){
        for(int j=0; j<=3; j++){
            printf("%s ", Participants[i][j]);
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