/*
Задача 11.
Направете същото ползвайки fgetpos().
int fgetpos(FILE *pfile, fpos_t *position);
Първият параметър е указател към файла, вторият параметър е
указател към стандартен параметър дефиниран в stdio.h
Типа fpos_t може да запише всяка позиция във файла.
Функцията връща 0 при успех и различно от 0 при грешка.
Дефинирайте променлива за fpos_t.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pfile = NULL;
    int fpos = 0;
    fpos_t position;
    char *filename = "Task11.txt";
    char StrWrt[] = "This is a test string to write";

    fopen_s (&pfile, filename, "w+");
 // pfile = fopen(filename, "w+");

    if(pfile==NULL){
        printf("Failed to open %s.\n", filename);
    }
    
    else{
        fputs(StrWrt, pfile);
        fprintf(pfile, "\n\n%s %s %s", "This is", "a test to write", "bez da ni boli sartzeto ;)");   
    }

   // fpos = ftell(pfile);
    fgetpos(pfile, &position);
    fclose(pfile);
    printf("\nFile size is %d", fpos);
    printf("File size is %d", position);
    pfile = NULL;
}