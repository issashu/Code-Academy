#include <stdio.h>

#define PI 2
#define E 3
#define swap(t, x, y) z=x; x=y; y=z;

int main() {
    int x= PI*E;
    int y=1;
    int z=0;
    printf("X before swap: %d\n", x);
    printf("Y before swap: %d\n\n", y);

    swap(int, x, y);

    printf("X after swap: %d\n", x);
    printf("Y after swap: %d\n", y);
}