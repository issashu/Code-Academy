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
void Getter();


int main(){
    int NumberBooks = 0;
    struct tagPaper *LibraryShelf = NULL;
    printf("How big is your library?\n");
    scanf("%d", &NumberBooks);
    Setter(NumberBooks, LibraryShelf);
    free(LibraryShelf);
}


void Setter(int BookNr, struct tagPaper *Shelf){
    Shelf = (struct tagPaper *) malloc(sizeof(struct tagPaper));
}

void Filler (int BookNr, struct tagPaper *Shelf){
    for (int i = 0; i < BookNr; i++){
        printf("\nPlease supply catalog data for book %d :\n", i);
        printf("Book ID: ");
        scanf("%d", Shelf->m_nBookId);
        printf("Title: ");
        scanf("%s", Shelf->m_szTitle);
        printf("Author: ");
        scanf("%s", Shelf->m_szAuthor);
        printf("Short description: ");
        scanf("%d", Shelf->m_szSubject);
    }
}

void Getter(int BookNr, struct tagPaper *Shelf){
        char Query[64] = {'s'};
        printf("What book do you need info about? (Max 64 chracters)\n");
        fgets(Query,)



}