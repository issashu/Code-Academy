
#include <stdlib.h>
#include <stdio.h>

void *p;
int main() {
  p = malloc(7);
  p = 0; // The memory is leaked here.
  return 0;
}

/*
clang -fsanitize=address -g Memsan.c ; ASAN_OPTIONS=detect_leaks=1 ./a.out
*/