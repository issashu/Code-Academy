/*
Задача 8.
Напишете програма, която да представя Реда на Фибоначи в масив.
Ред на Фибоначи: Всяко число е равно на сумата на двете преди него.
Първите 2 са 0 и 1. 
*/

#include <iostream>

int sequence(unsigned n)
{
    // Smart code goes here
    int sumEL = 0;
    int El1 = 0;
    int El2 = 1;

    for (int i = 2; i < n; i++)
    { 
        sumEL = El1 + El2;
        El1 = El2;
        El2 = sumEL;
      
    }
    return sumEL;
}

int main(int argc, char* argv[])
{
    std::cout << sequence(4) << std::endl;

	return 0;
}