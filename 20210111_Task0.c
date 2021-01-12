#include <stdio.h>

int addDigit(int a, int b);

int main()
{
    int a=0;
    int b=0;

    printf("a is ?:");
    scanf("%d", &a);

    printf("b is ?:");
    scanf("%d", &b);

    addDigit(a, b);

}

int addDigit(int a, int b)
{
    printf("The result of %d + %d is: %d", a, b, (a+b));
}