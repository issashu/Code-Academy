/*
Задача 1.
Напишете програма, която сравнява два файла, като отпечатва 
първият ред на който се различават и на двата файла.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CmpFiles(char *BufferOne, char *BufferTwo,int *LineCounterOne,int *LineCounterTwo);
int CountFileLines(int *LineCounterOne,int *LineCounterTwo);

int main(){
    int LineCountOne = 0;
    int LineCountTwo = 0;
    char *bufferOne=malloc(500*sizeof(char));
    char *bufferTwo=malloc(500*sizeof(char));

    CountFileLines(&LineCountOne, &LineCountTwo);
    CmpFiles(bufferOne, bufferTwo, &LineCountOne, &LineCountTwo);
}

int CountFileLines(int *LineCounterOne,int *LineCounterTwo){
    FILE *FPOne = fopen("Task1.txt", "r");
    FILE *FPTwo = fopen("Task1_2.txt", "r");

    if (FPOne == NULL || FPTwo==NULL){
        printf("Files did not load correctly!");
        exit(1);
    }

    for (char c= getc(FPOne); c!= EOF; c= getc(FPOne)){
        if (c == '\n'){
            LineCounterOne += 1;
        } 
    }

    for (char c = getc(FPTwo); c != EOF; c = getc(FPTwo)){
        if (c == '\n'){
            LineCounterTwo += 1;
        } 
    }
    fclose(FPOne);
    fclose(FPTwo);
}

void CmpFiles(char *BufferOne, char *BufferTwo, int *LineCounterOne, int *LineCounterTwo){
    int i = 0;
    FILE *FPOne = NULL;
    FILE *FPTwo = NULL;
    FPOne=fopen("Task1.txt","r");
    FPTwo=fopen("Task1_2.txt","r");
    fseek(FPOne,0,SEEK_SET);
    fseek(FPTwo,0,SEEK_SET);

    while(i<=*LineCounterOne && i<=*LineCounterTwo){
        fscanf(FPOne,"%[^\n]s", BufferOne);
        fscanf(FPTwo,"%[^\n]s", BufferTwo);
        
        if(strcmp(BufferOne,BufferTwo)!=0){
            printf("The two selected files differ at line %d with text:\n", i);
            printf("File 1: %s\n", BufferOne);
            printf("File 2: %s\n", BufferTwo);
            exit(0);
        }
        else{
            i++;
        }
    }
    printf("Reached the end of one of the two files.\n");

    fclose(FPOne);
    fclose(FPTwo);
}
