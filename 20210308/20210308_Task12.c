/*
Задача 12.
Изместете позицията си във файла 7 байта след началото, ползвайки fseek.
int fseek(FILE *pfile, long offset, int original);
Първият параметър е указател към файла, вторият и третият параметър 
оказват къде точно искаме да отидем във файла.
Референтни точки с предварително дефинирани имена:
SEEK_SET- началото на файла
SEEK_CUR- текуща позиция
fseek(fp, -10L, SEEK_CUR); връща на зад от текупата 10 bytes.
SEEK_END- края на файла
fseek(fp,0L, SEEK_END);
При текстови файлове, вторият аргумент трябва да е стойността върната от 
ftell()
За текстови файлови третият аргумент трябва да е SEEK_SET, за бинарни 
файлове и просто число в байтове.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pfile = NULL;
    char *filename = "Task12.txt";
    fopen_s (&pfile, filename, "w+");

    char StrWrt[] = "This is the string to overwrite them all!";
    char StrRds[800];
    fputs(StrWrt, pfile);

    fseek(pfile, 7, SEEK_SET);
    fscanf(pfile,"%[^\n]", StrRds);
    
    printf("%s", StrRds);
}