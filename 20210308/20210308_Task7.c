/*
Напишете символ в текстов файл.
Int fputc(int ch, FILE *pfile);
Първият параметър е символът, който искаме да отпечатаме (изразен като
int, т.е. номер в ASCII таблицата), вторият е самия файл, в който ще пишем.
Ако е успешно, функцията връща това, което искаме да изпише.
При грешка функцията връща EOF.
putc () работи със същите аргументи, но е дефинирана като макрос в
стандартната библиотека.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *pfile = NULL;
    char *filename = "Task7.txt";
    char StrWrt[] = "This is a test string to write";

    /*w+ means the file is in both read and write mode at the same time*/
    fopen_s (&pfile, filename, "w+");

    if(pfile==NULL){
        printf("Failed to open %s.\n", filename);
        exit(1);
    }
    else{
        for (int i =0; i<strlen(StrWrt); i++){
            fputc(StrWrt[i], pfile);    
        }
    }
    
    fclose(pfile);
    pfile = NULL;
}