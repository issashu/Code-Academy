/*
Задача 6. Напишете програма на С, която чрез функция да обръща
десетични числа в двоични.
*/

#include<stdio.h>    

void PrintBinary(int number);

int main(){      
    int n;
    printf("Enter the number to convert: ");    
    scanf("%d",&n);
    PrintBinary(n);   
        
    return 0;  
}  

void PrintBinary(int number){
    
int binarray[64];
    
    for (int i=0;number>0;i++)    
    {    
        binarray[i]=number%2;    
        number=number/2;
    }    
    
    printf("\nBinary of Given Number is=");    
    for(int i=i-1;i>=0;i--)    
    {    
        printf("%d", binarray[i]);    
    }
}