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
    int  LineNr;
    char Type;
    bool Flags;
} skoba;

void CheckBrackets(skoba *Stack, char *FileName);

void ShowErrors(skoba *Stack, int *Index);

int main(){
    skoba *Stack = calloc(MAX_STACK,sizeof(skoba));
    char *FileName;

    printf("Please enter the name of the .c file to check. Make sure it is in the same path as this program:\n");
    scanf("%s", FileName);

    CheckBrackets(Stack, FileName);
    printf("End of file reached. All mistakes, if any printed above.\n");
    
    free (Stack);
    free (FileName);
}

void CheckBrackets(skoba *Stack, char *FileName){
    int StackIndex = 0;
    int LineCounter = 0;
    int i = 0;
    FILE *pfile;
    pfile = fopen(FileName, "r"); 

    if(pfile== NULL){
        printf("Error opening file on line 42 in the .c file.");
        exit(1);
    }

    for (char c = getc(pfile); c != EOF; c = getc(pfile)){
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
                for (i=StackIndex-1; i>=0; i--){
                    if(Stack[i].Type=='{' && Stack[i].Flags==true){
                        Stack[i].Flags=false;
                        break;
                    }
                }
            break;

            case ']':
                for (i=StackIndex-1; i>=0; i--){
                    if(Stack[i].Type=='[' && Stack[i].Flags==true){
                        Stack[i].Flags=false;
                        break;
                    }
                }
            break;

            case ')':
                for (i=StackIndex; i>=0; i--){
                    if(Stack[i].Type=='(' && Stack[i].Flags==true){
                        Stack[i].Flags=false;
                        break;
                    }
                }
            break;
        } 
    }
    ShowErrors(Stack, &StackIndex);
    fclose(pfile);
}

void ShowErrors(skoba *Stack,  int *Index){
    for(int i=0; i<=*Index; i++){
        if(Stack[i].Flags==true){
            printf("A \" %c \" bracket has been left opened at line %d\n", Stack[i].Type, Stack[i].LineNr+1);
        }
    }
}