/*
Code designer: George
Proofreading and optimization: Iordan & George

Да се състави програма, с помощта на която играч може да
играе (с право на връщане на ходовете) следната игра СОЛИТЕР:
На игралното поле са поставени 16 номерирани пулове и три реда
с по осем позиции. Целта е да се извадят от игра всички пулове с
изключение на номер 1. Може да се прескача през някой пул на
свободна клетка, но не се разрешава движение по диагонал.
Например възможни са ходове 1-9; 2-10; 1-2 и т.н. По тази схема 1
прескача 9 и 9х излиза от игра – отстранява се от полето, след
това 2 прескача 10 и 10 отпада от играта; по-нататък 1 прескача 2 и
2 излиза от игра.

*/

#include <stdio.h>
#include <ctype.h>

void testFunP(int SOLITARE[][8]);
void testFun(int SOLITARE[][8]);


int main(){
    int SOLITARE [3][8]={{45,45,45,45,45,45,45,45},
                         {9,10,11,12,13,14,15,16},
                         {1, 2, 3, 4, 5, 6, 7, 8,}
                        };
    testFunP(SOLITARE);

    while(1){   
        testFun(SOLITARE);
    }
}

void testFunP(int SOLITARE[][8]){
    
    for( int p=0;p<3;p++){
        for(int k=0;k<8;k++){
            if(SOLITARE[p][k]==45){
                printf("\t%c",SOLITARE[p][k]);
                }
            else{
            printf("\t%d ",SOLITARE[p][k]);
            }
        }
    printf("\n");
    }
}

void testFun(int SOLITARE[][8]){
    int indexI, indexJ;
    static int backUp[3][8];
    int choice;
    int choice1;
    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++){
            backUp[i][j]=SOLITARE[i][j];
       }
    }
    printf("Chose a number from 1 to 16 to move\n");
    scanf(" %d",&choice);

    if(isalpha(choice1) == 0){
        for(int i=0;i<3;i++){
            for(int j=0;j<8;j++){
                if(SOLITARE[i][j]==choice){
                    indexI=i;
                    indexJ=j;
                    break;
                }    
            }
        }
        scanf(" %d",&choice1);

        switch (choice1){
            case 1:
            /*nadqsno*/
                if(indexJ+2>7 || SOLITARE[indexI][indexJ+2]!=45 || SOLITARE[indexI][indexJ+1]==45|| SOLITARE[indexI][indexJ+1]==1 ){
                    printf("chose different path\n");
                }
                else{
                    SOLITARE[indexI][indexJ+2]=SOLITARE[indexI][indexJ];
                    SOLITARE[indexI][indexJ]=45;
                    SOLITARE[indexI][indexJ+1]=45;
                }
            break;

            case 2:
            /*nagore*/
                if(indexI-2<0 || SOLITARE[indexI-2][indexJ]!=45 || SOLITARE[indexI-1][indexJ]==45 || SOLITARE[indexI-1][indexJ]==1){
                    printf("chose different path\n");
                }
                else{
                    SOLITARE[indexI-2][indexJ]=SOLITARE[indexI][indexJ];
                    SOLITARE[indexI-1][indexJ]=45;   
                    SOLITARE[indexI][indexJ]=45;
                }
            break;

            case 3:
            /*nadolu*/
                if(indexI+2>2 || SOLITARE[indexI+2][indexJ]!=45 || SOLITARE[indexI+1][indexJ]==45 || SOLITARE[indexI+1][indexJ]==1){
                    printf("chose different path\n");
                }
                else{
                    SOLITARE[indexI+2][indexJ]=SOLITARE[indexI][indexJ];
                    SOLITARE[indexI+1][indexJ]=45;   
                    SOLITARE[indexI][indexJ]=45;
                }
            break;

            case 4: 
            /*nalqvo*/  
                if(indexJ-2<0||SOLITARE[indexI][indexJ-2]!=45 || SOLITARE[indexI][indexJ-1]==45 || SOLITARE[indexI][indexJ-1]==1 ){
                    printf("chose different path\n");
                }
                else{
                    SOLITARE[indexI][indexJ-2]=SOLITARE[indexI][indexJ];
                    SOLITARE[indexI][indexJ]=45;
                    SOLITARE[indexI][indexJ-1]=45;
                }
            break;
        }
    }   

    testFunP(SOLITARE);
    printf("do you want to rewind your board\n");
    scanf(" %d",&choice1);
    if(choice1==5){
        for(int i=0;i<3;i++){
            for(int j=0;j<8;j++){
                SOLITARE[i][j]=backUp[i][j];
            }
        }
        testFunP(SOLITARE);
    }
}
