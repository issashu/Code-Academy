/*
Задача 13. Представете служителите във фирма в структура с членове: 
пореден номер, име, презиме, фамилия, позиция, трудов стаж в години, заплата в лева, 
указател към структурата, описващ неговия началник. Напишете програма, която въвежда 
10 служителя, които се съхраняват в масив от описаните структури. 
Въвеждането на служителите може да стане на два паса, първо въвеждане на всички данни
 без указателя към началника и на втори пас, указване на всеки служител кой е неговият 
 началник.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Employee{
    int EmpID;
    char Surname[50];
    char FamilyName[50];
    char MiddleName[50];
    char Position[50];
    char Department[50];
    int Experience;
    int Salary;
    struct Manager *Supervisor;
} Slujitel_t;

typedef struct Manager{
    char Name[50];
    char Department[50];
} Management_t;

void Setter(Slujitel_t *Employee, Management_t *Manager, short MaxEmp, short MaxMan);
void Printer();
Slujitel_t Getter();

int main(){
    short TotalEmp = 0;
    short TotalMan = 0;
    Slujitel_t *Employees = NULL;
    Management_t *Managers = NULL;

    printf("How many employees do you have in the company?\n");
    scanf("%d", &TotalEmp);
    printf("How Managers  are available?");
    scanf("%d", &TotalMan);

    Setter(Employees, Managers);

    free(Employees);
    free(Managers);

}

void Setter(Slujitel_t *Employee, Management_t *Manager, short MaxEmp, short MaxMan){
    Employee = malloc(MaxEmp*sizeof(Slujitel_t));
    Manager = malloc (MaxMan*sizeof(Management_t));
    for(int i=0; i<MaxEmp; i++){
        printf("Please enter the Employee name:\n");


    }     
}

void Printer(){

}

slujitel Getter(){

}