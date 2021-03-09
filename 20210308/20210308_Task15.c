/*
Задача 15.
Напишете програма, която печата съдържанието на файл в обратен 
ред.
Използвайте fseek функцията, за да отидете накрая на файла. 
Използвайте ftell функцията, за да намерите позицията на пойнтера. 
Покажете на екран файла, обърнат в обратен ред.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* SwapText (char *string);

int main(){
    FILE *originalpf = NULL;
    char *filename_origin = "Task15.txt";
    char *buffer = malloc (60*sizeof(char));
    int pos = 0;
    originalpf = fopen(filename_origin, "r+");

    if (originalpf==NULL){
        printf("The file did not open! Kthnxbye.");
        exit(1);
    }
   /* This does not work...using a buffer inbetween
    fseek(originalpf,0,SEEK_END);
    pos = ftell(originalpf);

    for (int i=pos-1; i>0; i--){
        fprintf(stdout,"%c",originalpf);
        fseek(originalpf,0+i,SEEK_SET);
    }
    */

    fscanf(originalpf,"%[^\32]s", buffer);    
    SwapText(buffer);
    printf("%s", buffer);

    fclose(originalpf);
    free(buffer);
}

char* SwapText(char *string){
    int len = strlen(string)-1;
    char temp = 'e';
    for (int i=0; i <=len/2; i++){
        temp = string[len-i];
        string[len-i] = string[i];
        string[i] = temp;
    }
}