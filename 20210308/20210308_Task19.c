/*
Задача 19:
Напишете стандартната програма за Linux cat , която приема като 
аргументи от командния ред имена на файлове и изкарва съдържанието 
им на стандартния изход. Ако на програмата не са подадени никакви 
аргументи, то тя да изкара съдържанието подадено от стандартния вход 
на стандартния изход.
*/
#include <stdio.h>
#include <stdio.h>

int CatFunct(char** argv);
void ErrorHandler(int ErrNum);

int main(int argc, char** argv){
    int FuncResult = 0;
    if (argc==1){
        printf("Not implemented yet!");
        return 0;
    }
    else if(argc>2){
        printf("Usage cat <filename.extension>\n");
    }
    else if(argc == 2){
        FuncResult = CatFunct(argv[1]);
        ErrNum(FuncResult);
    }
    
}

int CatFunct((char** argv){
    FILE *FilePoionter = NULL;
    char *filename = NULL;
    scanf("cat %s", filename);
    FilePoionter = fopen(filename,"r");
    if(FilePoionter==NULL){
        return 404;
    }
    else {
        fprintf(stdin,"%s",FilePoionter);
        return 0;
    }
}

void ErrorHandler(int ErrNum){
    switch (ErrNum){
    case 404:
        printf("404.File not found.");
        printf("Usage cat <filename.extension>\n");
    break;

    case 0:
        printf("\nHope you got what you wanted. Have a nice day!\n");
    break;
    }
}
