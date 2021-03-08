/*
Задача 8.
Напишете стринг в текстов файл. 
int fputs (const char *str, FILE *pfile);
Първият параметър е указател към стринга, който искаме да 
запишем, вторият параметър е указател към файла, в който ще 
пишем.
Функцията ще записва символи от стринга догато достигне 
терминиращ символ \0, но не го пише в новия файл.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pfile = NULL;
    char *filename = "Task8.txt";
    char StrWrt[] = "This is a test string to write";

    fopen_s (&pfile, filename, "w");

    if(pfile==NULL){
        printf("Failed to open %s.\n", filename);
        exit(1);
    }
    else{
        fputs(StrWrt, pfile);
        fprintf(pfile, "\n\n%s %s %s", "This is", "a test to write", "bez da ni boli sartzeto ;)");
    }
    
    fclose(pfile);
    pfile = NULL;
}