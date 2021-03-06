#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GENERIC_MAX(TYPE) \
    TYPE TYPE##_max(TYPE x, TYPE y){\
        return x > y ? x : y;\
    }

GENERIC_MAX (int)
GENERIC_MAX (float)
GENERIC_MAX (char)

int main(int argc, char **argv) {

  	int *array = (int*) malloc(100*sizeof(int));
	int a = 0;
    float b=0.00;
    char c ='q';
  	array[10] = 100;
	int d = 0;
	int DirtyDiana = 0;
    float Bad=0.00;
    char Billy_Jean ='q';

    a = int_max(2,3);
    b = float_max(2.3, 4.56);
    /*Empty comment space*/
    
	free (array);
    c = char_max('c', 'u');
	d = array[10];

	printf(" a is: %d\n b is: %.2f\n c is: %c\n d is: %d\n", a, b, c, d);
  	
	return array[argc];
}

// clang -O1 -g -fsanitize=address -fno-omit-frame-pointer LectureTest.c 
