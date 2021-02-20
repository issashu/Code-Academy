/*
Задача 1. Дефиниране на структура, достъп до членове
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

struct tagPaper {
    unsigned m_nBookId;
    char m_szTitle[64]; 
    char m_szAuthor[64]; 
    char m_szSubject[256];
};

void Setter(int BookNr, struct tagPaper *Shelf);
void Filler (int BookNr, struct tagPaper *Shelf);
void Getter(int BookNr, struct tagPaper *Shelf);


int main(){
    int NumberBooks = 0;
    char Answer = 'y';
    struct tagPaper *LibraryShelf = NULL;
    printf("How big is your library?\n");
    scanf("%d", &NumberBooks);
   // Setter(NumberBooks, LibraryShelf);
    LibraryShelf = realloc(LibraryShelf, NumberBooks*sizeof(struct tagPaper));
    if(LibraryShelf ==NULL){
        printf("IKEA furniture missing....");
    }
    else{
        printf("%p", LibraryShelf);
    }
    Filler(NumberBooks, LibraryShelf);
    printf("Do you need info about a book (y for yes, anykey for no?\n");
    scanf(" %c", &Answer);
    if (Answer =='y'){
        Getter(NumberBooks, LibraryShelf);
    }
    free(LibraryShelf);
}


/*void Setter(int BookNr, struct tagPaper *Shelf){
    Shelf = realloc(Shelf, BookNr*sizeof(struct tagPaper));
    if(Shelf ==NULL){
        printf("IKEA furniture missing....");
    }
    else{
        printf("%p", Shelf);
    }
}*/

void Filler (int BookNr, struct tagPaper *Shelf){
    for (int i = 0; i < BookNr; i++){
        printf("\nPlease supply catalog data for book %d :\n", i);
        printf("Book ID: ");
        scanf("%d", &Shelf[i].m_nBookId);
        printf("Title: ");
        scanf(" %s", &Shelf[i].m_szTitle);
        printf("Author: ");
        scanf(" %s", &Shelf[i].m_szAuthor);
        printf("Short description: ");
        scanf(" %d", &Shelf[i].m_szSubject);
    }
}

void Getter(int BookNr, struct tagPaper *Shelf){
    char Query[64] = {'s'};
    char *BookFound = NULL;
    strstr(Shelf->m_szTitle, fgets(Query, sizeof (char), stdin));
    printf("What book do you need info about? (Max 64 chracters title)\n");
    BookFound = strstr(Shelf->m_szTitle, fgets(Query, sizeof (char), stdin));
    for(int i = 0; i < BookNr; i++){
        if(BookFound == Shelf[i].m_szTitle){
            printf("%d th book found", i);
            printf("ID: %d\n", Shelf[i].m_nBookId);
            printf("Title: %s\n", Shelf[i].m_szTitle);
            printf("Author: %s\n", Shelf[i].m_szAuthor);
            printf("Subject: %s\n", Shelf[i].m_szSubject);
        }
    }
}