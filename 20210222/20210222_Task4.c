/*
Задача 4.
Дефинирайте структура “date” с членове ден, месец, година. Създайте
променлива към структурата “contractdate”. По колко начина можете да
я дефинирате?
Задайте стойност на членовете на структурата по три различни начина.
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct __attribute__((__packed__)){
    uint8_t Day;
    uint8_t Month;
    uint16_t Year;
} date;

int main(){
	date ContractDate = {12, 10, 1984};
	date ContractDate = {.Year = 1981, .Day = 12, .Month = 11};
	date *pDateContract = &ContractDate;

	ContractDate.Day = 1;
	ContractDate.Month = 9;
	pDateContract->Year = 1987;

	printf("%d.%d.%d", ContractDate.Day, ContractDate.Month, pDateContract->Year);
}
