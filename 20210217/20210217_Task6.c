/*
Задача 6.
Пребройте буквите ‚а‘ в стринг (може да е число и масив).
Пример: "This is a string to test my idea for search in a char and ....";
*/

#include <stdio.h>

int CountCharacters (char *String, char* Searched);

int main(){
    char String[80] ={'a'};
    char SearcheFor ='a';
    int Occurancies = 0;

    printf("Please enter a string (max 80 characters will be read):\n");
    fgets(String, sizeof String, stdin);
    printf("\n\nYou have entered:\n%s", String);

    printf("What character are we looking for?\n");
    scanf("%c", &SearcheFor);

    Occurancies = CountCharacters(String, &SearcheFor);
    printf("The letter %c has been found %d times in the string!\n", SearcheFor, Occurancies);
}

int CountCharacters (char *String, char *Searched){
    int CharacterCounter = 0;

    for (String; *String; String++){
        if((*String) == (*Searched)){
            CharacterCounter++;
        }
    }
    return CharacterCounter;
}
