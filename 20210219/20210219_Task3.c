/*
Задача 3. Указатели към структура, предаване на структура на функция по
стойност и по референция
*/

#include <stdio.h>
#include <string.h>

void printPaper( struct tagPaper paper );
void printerPaper( struct tagPaper* paper );

struct tagPaper {
unsigned m_nBookId;
char m_szTitle[64];
char m_szAuthor[64];
char m_szSubject[256];
};

int main(){
    struct tagPaper Book = {.m_nBookId = 19, .m_szTitle = "Book Title"};
    printPaper(Book);

    printPaper(Book);
    printerPaper(&Book);
}

void printPaper( struct tagPaper paper ) { 
printf( "Paper id : %d\n", paper.m_nBookId);
printf( "Paper title : %s\n", paper.m_szTitle);
printf("\n");
}

void printerPaper( struct tagPaper* paper ) { 
printf( "Paper id : %d\n", paper->m_nBookId);
printf( "Paper title : %s\n", paper->m_nBookId);
printf("\n");
}