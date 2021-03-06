/*
Задача 3.
Създайте test1.txt файл в избрана от вас директория. Сложете някакви 
данни в него на латиница - име, поздрав, брой. Отворете за четене. 
Използвайте fgetc() , която взема само един char от файла. Направете 
while цикъл, за да изпишете всички символи, проверявайте за край на 
файл с EOF. Проверявайте дали файловият пойнтер не е NULL, ако е 
NULL, изпишете грешка.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pfile = NULL;
    char *filename = "Task2.txt";

//  fopen_s (&pfile, filename, "r");
    pfile = fopen(filename, "r");

    if(pfile==NULL){
        printf("Failed to open %s.\n", filename);
    }
    else{
        char c = fgetc(pfile); 
        while (c != EOF){ 
            printf ("%c", c); 
            c = fgetc(pfile); 
        }
    }
    
    fclose(pfile);
    pfile = NULL;
}   
