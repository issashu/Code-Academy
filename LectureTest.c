#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  	int *array = (int*) malloc(100*sizeof(int));
  	array[10] = 100;
  	free (array);
  	printf("%d", array[10]);
  	return array[argc];
}