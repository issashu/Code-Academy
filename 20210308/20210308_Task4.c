/*
Задача 4.
Прочетете стринг от създадения файл.
char *fgets(char * str, int nchars, FILE *stream)
 първият параметър е стринг, вторият параметър е брой символи, който 
искаме да прочетем, освен ако не стигне терминиращия символ за край 
на реда \n или \0 първо, третият е пойнтер към файла;
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pfile = NULL;
    char *filename = "Task2.txt";
    char string[400];

    pfile = fopen(filename, "r");

    if(pfile==NULL){
        printf("Failed to open %s.\n", filename);
    }
    else{
        fgets(string, 200, pfile);     
    }

    printf("%s\n", string);
    
    fclose(pfile);
    pfile = NULL;
}