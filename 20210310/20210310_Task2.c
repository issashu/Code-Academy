/*
Задача 2.
Напишете програма, която проверява дали всички отворени скоби {, (, [ за затворени ] ),},
Хвърлете грешка при липса на затварящи скоби и реда на който са.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK 100

typedef struct{
    int  BracketNR;
    char Type;
    int  LineNr;
    bool Flags;
} skoba;

void CheckBrackets(skoba *Stack, char *FileName);

int main(){
    skoba *Stack = malloc(MAX_STACK*sizeof(skoba));
    char *FileName = NULL;

    printf("Please enter the name of the .c file to check. Make sure it is in the same path as this program:\n");
    scanf("%s", FileName);

    CheckBrackets(Stack, FileName);

    free (Stack);
    free (FileName);
}

void CheckBrackets(skoba *Stack, char *FileName){
    int StackIndex = 0;
    int LineCounter = 0;
    FILE *C_File = fopen(FileName, "r");


    for (char c = getc(C_File); c != EOF; c = getc(C_File)){
        switch (c){
            case '\n':
                LineCounter++;
            break;

            case '{':
                Stack[StackIndex].BracketNR = StackIndex;
                Stack[StackIndex].Type = c;
                Stack[StackIndex].LineNr = LineCounter;
                Stack[StackIndex].Flags = true;
                StackIndex++;
            break;

            case '[':
                Stack[StackIndex].BracketNR = StackIndex;
                Stack[StackIndex].Type = c;
                Stack[StackIndex].LineNr = LineCounter;
                Stack[StackIndex].Flags = true;
                StackIndex++;
            break;

            case '(':
                Stack[StackIndex].BracketNR = StackIndex;
                Stack[StackIndex].Type = c;
                Stack[StackIndex].LineNr = LineCounter;
                Stack[StackIndex].Flags = true;
                StackIndex++;
            break;

            case '}':
                for (int i=StackIndex; i>=0; i++){
                    if(Stack[i].Type=='{' && Stack[i].Flags==true){
                        
                    }
                }

        } 
    }

}