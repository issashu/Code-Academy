/*
Задача 23.
Използване на метода на мехурчето за сортиране на масив от
числа (виж. wiki).
Потребителят въвежда броя числа и след това въвежда всяко
едно число. Напишете програма, която трябва да сортира числата
и да ги изведе в сортиран вид, като най-малкото се извежда първо.
Вариация: Да се направи същото с масив от символи.

Прави рандом числа от 1 до 10 за по-лесно разчитане.

For decreasing order use < instead of > @line 37
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  int Array[100] = {0};
  int MaxElements = 0;
  int Counter = 0;
  int Swap = 0;

  srand(time(0));

  printf("Enter number of elements\n");
  scanf("%d", &MaxElements);

  printf("Enter %d integers\n", MaxElements);

  for (Counter = 0; Counter < MaxElements; Counter++)
    Array[Counter] = rand()%10;

  for (Counter = 0 ; Counter < MaxElements - 1; Counter++)
  {
    for (int i = 0 ; i < MaxElements - Counter - 1; i++)
    {
      if (Array[i] > Array[i+1]) 
      {
        Swap       = Array[i];
        Array[i]   = Array[i+1];
        Array[i+1] = Swap;
      }
    }
  }

  printf("Sorted in ascending order:\n");
  for (Counter = 0; Counter < MaxElements; Counter++){
      printf("%d ", Array[Counter]);
  }

}