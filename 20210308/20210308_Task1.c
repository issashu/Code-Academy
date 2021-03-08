/*
Задача 1 Напишете програма, която чете стринг от стандартния вход и 
го извежда на стандартния изход с функцията gets(szBuf);

BUFSIZ is standard C Macro, which defines buffer size based on the machine running 
the code. It should not get less then 256 on any machine.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( ) { 
    char szBuf[BUFSIZ] = { 0 };
    FILE *p_file = NULL;
    fopen_s(&p_file,"Task1.txt","a");
        
    printf( "\nPlease enter some data to process: ");
    gets(szBuf);
    fputs(szBuf, p_file);
    fprintf(p_file, "\n%s", szBuf);
    printf( "\nData has been processed to (any similarities with initial text are purely accidental):\n");
    puts(szBuf);

    fclose(p_file);

    return 0;
}