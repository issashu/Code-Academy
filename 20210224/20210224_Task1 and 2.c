/*Задачи
1. Дефинирайте константи PI, Е, и други с помощта на макроси. Използвайте
ги в кода.
2. Напишете макрос swap(t, x, y), койтo променя местата на двата аргумента
от тип t.
*/

#include <stdio.h>

#define PI 2
#define E 3
#define swap(T, X, Y) X ^= Y ^= X ^= Y;

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