/*
Задача 5
Напишете програма, която чете числа от един текстов файл и ги записва 
в друг текстов файл.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pfile = NULL;
    char *filename = "Task2.txt";
    char string[400];

    fopen_s (&pfile, filename, "r");
 // pfile = fopen(filename, "r");

    if(pfile==NULL){
        printf("Failed to open %s.\n", filename);
    }
    else{
        fgets(string, 200, pfile);  
    //fgets reads one line and sets pointer to the end of the first line   
    }

    printf("%s\n", string);
    
    fclose(pfile);
    pfile = NULL;
}