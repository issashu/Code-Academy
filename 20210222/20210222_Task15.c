/*
Задача 15.
Дефинирайте структура с 4 полета (int. char[10], double, enum),
направете масив от 20 структури и ги попълнете. Изведете масива
от структури на стандартния изход в CSV формат (
https://en.wikipedia.org/wiki/Comma-separated_values ). Пример:
prog1 > structs20.cvs

https://austinrepp.com/how-to-write-to-a-csv-file-in-c/

*/

#include <stdio.h>

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
    
    team Employees;
    short MaxEmployees =20;

    for(int i=0; i<MaxEmployees;i++){
        Employees.ID = i+1;
        Employees.Name[10] = "John Doe";
        Employees.Salary = 1500+(i*2354);
        Employees.workplace = i;
    }

    fprintf(fpt,"ID, Name, Salary, Department\n");

    for(int i=0; i<MaxEmployees;i++){
        printf(fpt,"%d, %s, %lf, %d\n", Employees.ID, Employees.Name, Employees.Salary, Employees.workplace);
    }
    
    fclose(fpt);
}