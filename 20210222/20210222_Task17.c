/*
Дадени са следните структури и техният пакетиран вариант.
Разпечатайте заеманата от тях памет.
*/

#include <stdio.h>

typedef struct tagTestA {
    char m_ch;
    short int m_si;
} TTestA; 

typedef struct tagTestAP {
    char m_ch;
    short int m_si;
} __attribute__((packed)) TTestAP;

typedef struct tagTestB {
    short int m_si;
    char m_ch;
    int m_i;
} TTestB; 

typedef struct tagTestBP {
    short int m_si;
    char m_ch;
    int m_i;
} __attribute__((packed)) TTestBP;

typedef struct tagTestC {
    char m_ch;
    double m_d;
    int m_i;
} TTestC; 

typedef struct tagTestCP {
    char m_ch;
    double m_d;
    int m_i;
} __attribute__((packed)) TTestCP;

typedef struct tagTestD {
    double m_d;
    int m_i;
    char m_ch;
} TTestD; 

int main(){
    TTestA Var1;
    TTestAP Var2;
    TTestB Var3;
    TTestBP Var4;
    TTestC Var5;
    TTestCP Var6;
    TTestD Var7;


    printf("The RAM addresses are as follows:\n");
    printf("TTestA: %p\n", Var1);
    printf("TTestAP: %p\n", Var2);
    printf("TTestB: %p\n", Var3);
    printf("TTestBP: %p\n", Var4);
    printf("TTestC: %p\n", Var5);
    printf("TTestCP: %p\n", Var6);
    printf("TTestD: %p\n", Var7);

    printf("The occupied RAM sizes are as follows:\n");
    printf("TTestA: %d\n", sizeof(Var1));
    printf("TTestAP: %d\n", sizeof(Var2));
    printf("TTestB: %d\n", sizeof(Var3));
    printf("TTestBP: %d\n", sizeof(Var4));
    printf("TTestC: %d\n", sizeof(Var5));
    printf("TTestCP: %d\n", sizeof(Var6));
    printf("TTestD: %d\n", sizeof(Var7));

}