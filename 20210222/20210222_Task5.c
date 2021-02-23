/*
 Задача 5.
Направете масив от 10 структури от задача 4. Задайте стойност на 10 -те дати, по избор. 
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct __attribute__((__packed__)){
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;
} date;

int main(){
    srand(time(0));
	date ContractDate [10];
    int i=0;
    date *pDatePointer=NULL;

    for(int itt=0; itt<10; itt++){
        ContractDate[itt].Day = rand()%32;
        ContractDate[itt].Month = rand()%13;
        ContractDate[itt].Year = 1300+(rand()%800);
    }

    printf("Which of the 10 dates you want to print?\n");
    scanf("%d", &i);
    pDatePointer = &ContractDate[i];
	printf("%d.%d.%d", ContractDate[i].Day, ContractDate[i].Month, pDatePointer->Year);
}