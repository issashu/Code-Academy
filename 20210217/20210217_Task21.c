/*
Задача 21*.
Напишете програма, която изчислява детерминантата на матрица
(виж. wiki)

Assuming 3x3 matrix

    | a  b  c |
    | d  e  f |
    | g  h  i |

Formula: Determinant = a(ei-fh) -b(di-fg)+c(dh-eg)
*/

#include <stdio.h>
#define MAX_SIZE 3

void FillElements (char **Matrix);
long CalculateDeterminant (char **Matrix);

int main()
{
    int Matrix[MAX_SIZE][MAX_SIZE];
    long Determinant = 0;

    void (*Setter)(char **) = FillElements;
    long(*Getter)(char **) = CalculateDeterminant;

    Setter(Matrix);
    Determinant = Getter(Matrix);
    
    printf("Determinant of matrix A = %ld", Determinant);

    return 0;
}

void FillElements (char **Matrix){
    int Row = 0; 
    int Column = 0;

    printf("Enter elements in matrix of size 3x3: \n");
    for(Row=0; Row<MAX_SIZE; Row++){
        for(Column=0; Column<MAX_SIZE; Column++){
            scanf("%d", &Matrix[Row][Column]);
        }
    }

    printf("The Matrix you filled is:\n");
    for(Row=0; Row<MAX_SIZE; Row++){
        for(Column=0; Column<MAX_SIZE; Column++){
            printf(" %d", &Matrix[Row][Column]);
        }
        printf("\n");
    }
}

long CalculateDeterminant (char **Matrix){
    //Временни променливи за пресмятане
    int a, b, c, d, e, f, g, h, i = 0;
    int Row = 0; 
    int Column = 0;
    long Determinant;

    a = Matrix[0][0];
    b = Matrix[0][1];
    c = Matrix[0][2];
    d = Matrix[1][0];
    e = Matrix[1][1];
    f = Matrix[1][2];
    g = Matrix[2][0];
    h = Matrix[2][1];
    i = Matrix[2][2];

    Determinant = (a*(e*i - f*h)) - (b*(d*i - f*g)) + (c*(d*h - e*g));

    return Determinant;
}