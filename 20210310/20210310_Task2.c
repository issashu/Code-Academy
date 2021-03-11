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

int CheckBrackets(skoba *Stack, char *FileName);

void ShowErrors(skoba *Stack, int *Index);

int main(){
    skoba *Stack = malloc(MAX_STACK*sizeof(skoba));
    char *FileName = NULL;
    int Index =0;

    printf("Please enter the name of the .c file to check. Make sure it is in the same path as this program:\n");
   // scanf("%s", &FileName);

    Index = CheckBrackets(Stack, FileName);
    ShowErrors(Stack, &Index);

    free (Stack);
    free (FileName);
}

int CheckBrackets(skoba *Stack, char *FileName){
    int StackIndex = 0;
    int LineCounter = 0;
    FILE *C_File = fopen("20210310_Task1.c", "r");


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
                for (int i=StackIndex; i>=0; i--){
                    if(Stack[i].Type=='{' && Stack[i].Flags==true){
                        Stack[i].Flags==false;
                        break;
                    }
                }
            break;

            case ']':
                for (int i=StackIndex; i>=0; i--){
                    if(Stack[i].Type=='[' && Stack[i].Flags==true){
                        Stack[i].Flags==false;
                        break;
                    }
                }
            break;

            case ')':
                for (int i=StackIndex; i>=0; i--){
                    if(Stack[i].Type=='(' && Stack[i].Flags==true){
                        Stack[i].Flags==false;
                        break;
                    }
                }
            break;
        } 
    }

}

void ShowErrors(skoba *Stack,  int *Index){
    for(int i=0; i<=*Index; i++){
        if(Stack[i].Flags==true){
            printf("A \" %c \" bracket has been left opened at line %d\n", Stack[i].Type, Stack[i].LineNr);
        }
    }
}