#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>

void FirstTheorem(int A, int B);
void SecondTheorem(int A, int B);

int main()
{
    /*DeMorgan’s First Theorem
    https://www.electronics-tutorials.ws/boolean/demorgan.html

    DeMorgan’s First theorem proves that when two (or more) input variables are AND’ed and negated, 
    they are equivalent to the OR of the complements of the individual variables. 
    Thus the equivalent of the NAND function will be a negative-OR function, proving that !(A.B) = !A+!B. */
    int A=0;
    int B=0;

    FirstTheorem(A,B);
    SecondTheorem(A,B);

    
}

void FirstTheorem(int A, int B)
{
    A=1;
    B=1;
    printf("T1 Case 1: Value of A is %d and value of B is %d :\n");
    if(!(A&&B)==(!A||!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A&&B) = %d  and !A||!B = %d", (!A&&B), (!A||!B));
        printf("\n");
    }

    A=0;
    B=1;
    printf("T1 Case 2: Value of A is %d and value of B is %d :\n");
    if(!(A&&B)==(!A||!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A&&B) = %d  and !A||!B = %d", (!A&&B), (!A||!B));
        printf("\n");
    }

    A=1;
    B=0;
    printf("T1 Case 3: Value of A is %d and value of B is %d :\n");
    if(!(A&&B)==(!A||!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A&&B) = %d  and !A||!B = %d", (!A&&B), (!A||!B));
        printf("\n");
    }

    A=0;
    B=0;
    printf("T1 Case 4: Value of A is %d and value of B is %d :\n");
    if(!(A&&B)==(!A||!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A&&B) = %d  and !A||!B = %d", (!A&&B), (!A||!B));
        printf("\n");
    }
}

void SecondTheorem(int A, int B)
{
    A=1;
    B=1;
    printf("T2 Case 1: Value of A is %d and value of B is %d :\n");
    if(!(A||B)==(!A&&!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A||B) = %d  and !A&&!B = %d", (!A||B), (!A&&!B));
        printf("\n");
    }

    A=0;
    B=1;
    printf("T2 Case 2: Value of A is %d and value of B is %d :\n");
    if(!(A||B)==(!A&&!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A||B) = %d  and !A&&!B = %d", (!A||B), (!A&&!B));
        printf("\n");
    }

    A=1;
    B=0;
    printf("T2 Case 3: Value of A is %d and value of B is %d :\n");
    if(!(A||B)==(!A&&!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A||B) = %d  and !A&&!B = %d", (!A||B), (!A&&!B));
        printf("\n");
    }

    A=0;
    B=0;
    printf("T2 Case 4: Value of A is %d and value of B is %d :\n");
    if(!(A||B)==(!A&&!B))
    {
        printf("Thinking....");
        sleep(2);
        printf("The first theorem is true!\n");
        printf("!(A||B) = %d  and !A&&!B = %d", (!A||B), (!A&&!B));
        printf("\n");
    }
}