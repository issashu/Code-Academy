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
    int i=0;
 int DBEntries = 2;
 int StrLen = 30;
 int NrColumns = 3;
 int *DBSize = &DBEntries;
 int *NameLength = &StrLen;
 char **Participants = (char**) malloc (DBEntries * sizeof (char *));
 for ( i = 0; i<DBEntries; i++){
        Participants[i] = (char*) malloc (NrColumns * sizeof(char));
    }
    //EnterParticipant (Participants, DBSize, NameLength);
    char Answer ='y';
    do{
        printf("Please enter the Participant Name: \n");
        fgets(&Participants[i][0], *NameLength, stdin);
        printf("Please enter the Participant Surname: \n");
        fgets(&Participants[i][1], *NameLength, stdin);
        printf("Please enter the Participant Age: \n");
        fgets(&Participants[i][2], *NameLength, stdin);
        i++;
            if(i == (*DBSize-2)){
                *DBSize += *DBSize;
                Participants = realloc(Participants, *DBSize);
            }
        printf("Do you want to add further participants? (Press y for yes, anything else for no)\n");
        Answer = getchar();
    } while(Answer=='y');

    for(int i=0; i<*DBSize; i++){
        for(int j=0; j<=3; j++){
            printf("%s ", Participants[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<*DBSize; i++){
        for(int j=0; j<=3; j++){
            printf("%s ", Participants[i][j]);
        }
        printf("\n");
    }
    
    free(Participants);
}


/*

int ****Participants [10]      [30]    [30]            [1];
            por. Nr.   Ime     familia          Age
    
Particvipants [malloc]  [malloc] [malloc]      [1]
                [10]     [30]     [30]          [1]
                [realloc] [reLLOC] [RE3ALLOC]    [1]

*/