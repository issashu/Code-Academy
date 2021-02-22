#include <stdio.h>
#include <string.h>
struct tagPaper {
unsigned m_nBookId;
char m_szTitle[64];
char m_szAuthor[64];
char m_szSubject[256];
};


int main(){
    struct tagPaper Var1 = {1,"This is book", "This is author", "It is a bout a book and an author"};
    struct tagPaper Var2 = {2,"This is book", "This is author", "It is a bout a book and an author"};
    struct tagPaper Var3 = {3};
    strcpy( Var3.m_szTitle, "Paper title");
    strcpy( Var3.m_szAuthor, "Autor");
    strcpy( Var3.m_szSubject, "paper subject");

    printf("%d\n", Var1.m_nBookId);
    printf("%s\n", Var1.m_szTitle);
    printf("%s\n", Var1.m_szAuthor);
    printf("%s\n", Var1.m_szSubject);

    printf("%d\n", Var2.m_nBookId);
    printf("%s\n", Var2.m_szTitle);
    printf("%s\n", Var2.m_szAuthor);
    printf("%s\n", Var2.m_szSubject);

    printf("%d\n", Var3.m_nBookId);
    printf("%s\n", Var3.m_szTitle);
    printf("%s\n", Var3.m_szAuthor);
    printf("%s\n", Var3.m_szSubject);
}