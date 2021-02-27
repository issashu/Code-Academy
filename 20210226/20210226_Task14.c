#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define listSize 3

typedef struct participant{
    
 unsigned numOfPart;
 char *firstName;
 char *secondName;
 int age;
}participant;

void Sort(participant* participant0);


int main(){
 participant *participant0;
 
 participant0=malloc(listSize*sizeof(participant));

 int i;
 int count=0;
 char choice='1';
 for(i=0;choice!='0';i++){
    printf("enter the participant number\n");
    scanf(" %d",&participant0[i].numOfPart);
    printf("enter  the participant name : \n");
    participant0[i].firstName=malloc(20);
    scanf("%s",&participant0[i].firstName);
    printf("enter the participant second name : \n");
    participant0[i].secondName=malloc(20);
    scanf("%s",&participant0[i].secondName);
    printf("enter the participant age : \n");
    scanf(" %d",&participant0[i].age);
    count++;
    printf("do you have another participant to add.Press 1 or pres 0 for exit. \n");
    scanf(" %c",&choice);
}

Sort(participant0);

for(i=0;i<count;i++){
    printf("Num of part:%d\n",participant0[i].numOfPart);
    printf("First name:%s\n",&participant0[i].firstName);
    printf("Second name:%s\n",&participant0[i].secondName);
    printf("age : %d\n",participant0[i].age);
}

 free(participant0);
}
void Sort(participant* participant0){
    char *temp = NULL;
    int Number, i, j;

    for(i = 0; i < listSize-1; i++){
        for(j = i + 1; j < listSize; j++){

            if(strncmp(&participant0[i].firstName, &participant0[j].firstName, 1) > 0){
                
                temp = participant0[j].firstName;
                participant0[j].firstName = participant0[i].firstName;
                participant0[i].firstName = temp;

                temp = participant0[j].secondName;
                participant0[j].secondName = participant0[i].secondName;
                participant0[i].secondName = temp;

                temp = participant0[j].numOfPart;
                participant0[j].numOfPart = participant0[i].numOfPart;
                participant0[i].numOfPart = temp;

                temp = participant0[j].age;
                participant0[j].age = participant0[i].age;
                participant0[i].age= temp;
            }
        }
    }
}