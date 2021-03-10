#include <stdio.h>

#define CON stdout

int main() {
    FILE *console = NULL;

/*FOR LINUX we can use tty to send signal to console, while using pipe*/
    console = fopen("/dev/tty", "w");

    fprintf(console, "console\n");
    printf("piped\n");

    return 0;
}