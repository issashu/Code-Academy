
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


issashu@AsusG20:/mnt/f/CodeRepos/Code-Academy$ clang -fsanitize=address -g Memsan.c ; ASAN_OPTIONS=detect_leaks=1 ./a.out

=================================================================
==59==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 7 byte(s) in 1 object(s) allocated from:
    #0 0x493a1d in malloc (/mnt/f/CodeRepos/Code-Academy/a.out+0x493a1d)
    #1 0x4c3128 in main /mnt/f/CodeRepos/Code-Academy/Memsan.c:7:7
    #2 0x7f3658d480b2 in __libc_start_main /build/glibc-eX1tMB/glibc-2.31/csu/../csu/libc-start.c:308:16

SUMMARY: AddressSanitizer: 7 byte(s) leaked in 1 allocation(s).
issashu@AsusG20:/mnt/f/CodeRepos/Code-Academy$
*/
