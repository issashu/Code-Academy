/*
Задача 1. Направете две функции и извикайте желаната функция с
указател към функция, съобразно знака, подаден от командния ред: а.оut
20 + 3
*/

#include <stdio.h>
#include <stdlib.h>

int fnPlus(int nA, int nB);
int fnMinus(int nA, int nB);
int fnMulti(int nA, int nB);
int fnDiv(int nA, int nB);

int main(int argc, char* argv[]) {
    //pfCalc is a pointer to function returning int and having int and int as parameters
    int (*pfCalc) (int,int) = NULL;
    if (argc < 4){
        printf("\nUsage: %s +/- arg1 arg2\n", argv[0]);
    }
    else if ('-' == argv[1][0]) { 
        pfCalc = fnMinus; 
    }
    else if ('+' == argv[1][0]) {
        pfCalc = fnPlus; 
    }
    else if ('x' == argv[1][0]) {
        pfCalc = fnMulti; 
    }
    else if ('d' == argv[1][0] && argv[3][0]!='0') {
        pfCalc = fnDiv; 
    }
    (NULL == pfCalc) ? 0 : printf("\nResult: %d\n", (*pfCalc)(atoi(argv[2]), atoi(argv[3])));
    return 0;
}

int fnPlus(int nA, int nB) { 
    return(nA + nB); 
}
int fnMinus(int nA, int nB) { 
    return(nA - nB); 
}

int fnMulti(int nA, int nB){
    return (nA * nB);
}

int fnDiv(int nA, int nB){
    return(nA / nB);
}