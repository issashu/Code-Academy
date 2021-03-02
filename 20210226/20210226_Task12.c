/*
Задача 12. Представете служителите във фирма в структура с
членове: пореден номер, име, презиме, фамилия, позиция, трудов стаж в
години, заплата в лева, указател към структурата, описващ неговия
началник. Напишете програма, която въвежда 10 служителя, които се
съхраняват в масив от описаните структури. Въвеждането на служителите
може да стане на два паса, първо въвеждане на всички данни без
указателя към началника и на втори пас, указване на всеки служител кой е
неговият началник. В решението трябва да се използва динамично
заделяне на памет и typedef.
*/

#include <stdio.h>
#include <stdlib.h>

#define listSize 1

typedef struct information{
    int number;
    char *firstName;
    char *secondName;
    char *thirdName;
    char *position;
    int exp;
    float salary;
 }information;

void enterInformation(information *array);
void printList(information *array,information *manager);

int main(){
    information *array,*manager;
    array=manager=NULL;
    array=malloc(listSize*sizeof(information));
    manager=malloc(sizeof(information));
    manager->number=1;
    manager->firstName="Ivan";
    manager->secondName="Ivanov";
    manager->thirdName="Ivanov";
    manager->position="ceo";
    manager->salary=2500;
    manager->exp=25;

    enterInformation(array);
    printList(array,manager);
    
    free(array);
    free(manager);
}

void enterInformation(information *array){
    for(int index=0;index<listSize;index++ ){
        printf("Employee Informattion\n");
        printf("Enter employee number: ");
        scanf(" %d", &array[index].number);
        printf("Enter employee first name:");
        scanf(" %s", &array[index].firstName);
        printf("Enter employee middle name:");
        scanf(" %s", &array[index].secondName);
        printf("Enter employee family name:");
        scanf(" %s", &array[index].thirdName);
        printf("Enter employee position:");
        scanf(" %s", &array[index].position);
        printf("Enter employee work experience:");
        scanf(" %d", &array[index].exp);
        printf("Enter employee salary:");
        scanf(" %f", &array[index].salary);
    }
}

void printList(information *array,information *manager){
    for (int i = 0; i < listSize; i++){
        printf("=============================\n");
        printf("------Employee Details-------\n");
        printf("Employee number: %d\n", array[i].number);
        printf("Employee full name: %s %s %s\n", &array[i].firstName, &array[i].secondName, &array[i].thirdName);
        printf("Employee position: %s\n", &array[i].position);
        printf("Employee work experience: %d\n", array[i].exp);
        printf("Employee salary: %.2f\n", array[i].salary);
        printf("      Manager Details       \n");
        printf("Manager number: %d\n",manager->number);
        printf("Manager full name: %s %s %s\n", manager->firstName, manager->secondName, manager->thirdName);
        printf("Manager position: %s\n", manager->position);
        printf("Manager work experience: %d\n", manager->exp);
        printf("Manager salary: %.2f\n", manager->salary);
    }
}