#include <stdio.h>
#include <string.h>

typedef struct csv{
    int ID;
    char Name [10];
    double Salary;
    enum department{
        Accounting1,
        Sales2,
        Management3,
        Accounting4,
        Sales5,
        Management6,
        Accounting7,
        Sales8,
        Management9,
        Accounting10,
        Sales11,
        Management12,
        Accounting13,
        Sales14,
        Management15,
        Accounting16,
        Sales17,
        Management18,
        Accounting19,
        Sales20,
    }workplace;
} team;

int main(){
    FILE *fpt;
    fpt = fopen("20210222_Task15.csv", "w+");
    
    team Employees[20];
    short MaxEmployees =20;

    for(int i=0; i<MaxEmployees;i++){
        Employees[i].ID = i+1;
        strcpy(Employees[i].Name,"John Doe");
        Employees[i].Salary = (150+(i*254));
        Employees[i].workplace = i;
    }

    for(int i=0; i<MaxEmployees;i++){
        fscanf(fpt,"%d, %s, %.2lf, %d\n", Employees[i].ID, Employees[i].Name, Employees[i].Salary, Employees[i].workplace);
    }

   for(int i=0; i<MaxEmployees;i++)
    printf("%d, %s, %.2lf, %d\n", Employees[i].ID, Employees[i].Name, Employees[i].Salary, Employees[i].workplace);
    
    fclose(fpt);
}