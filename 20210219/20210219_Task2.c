#include <stdio.h>
#include <string.h>

//It is part of MinGW stdio.h and is 512
#define BUFSIZ 200

struct tagDetail {
unsigned m_uAcadId;
char m_szAcadName[BUFSIZ];
char m_szAcadUrl[BUFSIZ];
};

struct tagCadet {
unsigned m_uCadetId;
char m_CadetName[BUFSIZ];
float m_uAverageRating;
struct tagDetail m_detail;
};

int main(){
    struct tagCadet Cadet1 = {.m_uCadetId = 1, .m_CadetName = "John Doe", .m_detail.m_szAcadUrl="www.google.com"};

    printf("%d\n", Cadet1.m_uCadetId);
    printf("%s\n", Cadet1.m_CadetName);
    printf("%s\n", Cadet1.m_detail.m_szAcadUrl);

}