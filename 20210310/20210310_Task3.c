/*
Задача 3.
Напишете програма за отпечатване на файловете добавени след а.ехе , 
като започнете всеки нов на нова страница със заглавие и номере на всяка 
страница за всеки файл.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int PageSize = 42;

void FilePrinter(char* FileName);

int main(int argc, char** argv){
    if(argc == 1){
        printf("No files supplied.\n Usage: printer.exe <file1> <file2> ... <file n>\n");
    }
    else{
        for(int i=1; i<argc; i++){
            FilePrinter(argv[i]);
        }
    }
}

void FilePrinter(char* FileName){
    /*Prints title, then 42 lines, then page number, waits for a button press and repeats, until EOF*/
    static FILE *FilePointer = NULL;
    unsigned short PageNumber = 1;
    unsigned short LineCount = 0;

    fopen_s(&FilePointer, FileName, "r");
    
    printf("\t\t=== %s ===\t\t\n", FileName);
    
    for (char c = getc(FilePointer); c != EOF; c = getc(FilePointer)){
        if(LineCount<42){
            switch (c){
                case '\n':
                    printf("\n");
                    LineCount++;
                break;
        
                default:
                    printf("%c", c);
                break;
            }
        }
        else if(LineCount==42){
            printf("\t\t-- %hd --\t\t\n", PageNumber);
            LineCount=1;
            getchar();
            printf("\t\t=== %s ===\t\t\n", FileName);
        }
    }

    fclose(FilePointer);
    FilePointer=NULL;
}