/*
 Задача 2 Разширяване на заделена памет с realloc

 Смених с calloc, за да се инициализира с 0 и съм си направил да печата адресите от - до.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* piValue = NULL;
  unsigned uSize = 0;
  printf("\nEnter size: ");
  scanf("%u", &uSize);
  piValue = (int*) calloc(uSize, sizeof(int));
  if(NULL == piValue) {
      printf("Allocation memory error!\n");
      exit(1);
    }
    printf("Addresses of allocated memory is from: %p to %p\n", piValue, (piValue+uSize));
    printf("\nEnter the new size: ");
    scanf("%u", &uSize);
    piValue = realloc(piValue, uSize * sizeof(int)); 
    if(NULL == piValue) {
        printf("Reallocation memory error!\n");
        exit(2);
    }
    printf("Addresses of newly allocated memory: %p\n", piValue);
    free(piValue);
}