/*
 Задача 11.
Напишете програма, в която се въвеждат пореден номер, име, фамилия, възраст на участници в маратон. 
Изискването е за името и фамилията да не се използват масиви с фиксирана дължина. 
След като въвеждането завърши, изведете списък с участниците.

Тази задача е за структури (особенно за класове с полиморфизъм в С++) и би била елементарна с тях. 
Опита по-долу е да се използват само пойнтери, които да се движат в синхрон (без структури).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EnterParticipant (int *PartNumber, char *Name, char *Surname, int *Age, int *Size);
void IncreaseDB (int *PartNumber, char *Name, char *Surname, int *Age, int *Size);
void PrintDB (int *PartNumber, char *Name, char *Surname, int *Age, int *Size);

int main(){
 int *PartNumber=NULL;
 char *Surname = NULL;
 char *Name = NULL;
 int *Age=NULL;
 int DBEntries = 10;
 int *Size = &DBEntries;
 char Answer = 'y';

 PartNumber = calloc(10, sizeof(int));
 Surname = calloc (20, sizeof(char));
 Name = calloc (20, sizeof(char));
 Age = calloc (10, sizeof(int));

 do{
     EnterParticipant (PartNumber, Name, Surname, Age, Size);
     printf("Do you want to add further participants? (Press y for yes, anything else for no)\n");
     scanf(" %c", &Answer);
    } while(Answer=='y');

    PrintDB(PartNumber, Name, Surname, Age, Size);

    free(PartNumber);
    free(Surname);
    free(Name);
    free(Age);
}

void EnterParticipant (int *PartNumber, char *Name, char *Surname, int *Age, int *Size){
    static int i = 0;
    for(i; i < *Size; i++){
        //Database starts from 1 to be Human-readable, not Coder-readable
        PartNumber[i] = i+1;
        printf("Please enter the Participant Name: \n");
        scanf("[^\n]%s", Name[i]);
        printf("Please enter the Participant Surname: \n");
        scanf("[^\n]%s", Surname[i]);
        printf("Please enter the Participant Age: \n");
        scanf("%d", Age[i]);
        if(i == (*Size-2)){
            *Size += *Size;
            IncreaseDB(PartNumber, Name, Surname, Age, Size);
        }
    }
}
void IncreaseDB (int *PartNumber, char *Name, char *Surname, int *Age, int *Size){
    PartNumber = realloc (PartNumber, *Size);
    Name = realloc (Name, *Size);
    Surname = realloc (Surname, *Size);
    Age = realloc (Age, *Size);
}
void PrintDB (int *PartNumber, char *Name, char *Surname, int *Age, int *Size){
    for(int i=0; i<*Size; i++){
        printf("%d  ", PartNumber);
        printf("%s ", Name);
        printf("%s ", Surname);
        printf("%d", Age);
        printf("\n");
    }
}


/*

int ****Participants [10]      [30]    [30]            [1];
            por. Nr.   Ime     familia          Age
    
Particvipants [malloc]  [malloc] [malloc]      [1]
                [10]     [30]     [30]          [1]
                [realloc] [reLLOC] [RE3ALLOC]    [1]

Because own is declared as having type int *

int * own;
then own[i] is a scalar object of type int and you may not apply to it the subscript operator.

You could write the following way

int ( *own )[3] = calloc( mem_size, 3 * sizeof( int ) );
The other way is the following

int **own = malloc( mem_size * sizeof( int * ) );

for ( i = 0; i < mem_size; i++ ) own[i] = calloc( 3, sizeof( int ) );
 */