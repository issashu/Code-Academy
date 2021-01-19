# include <stdio.h> 

int main() 
{
    int nResult = 13; /* опитайте с други стойности - scanf for any desired value */ 
    int nX = 4;

    printf("Introduce some value for computations for nResult and after for nX: ");
    scanf ("%d", &nResult);
    scanf ("%d", &nX);


    printf("Result = %d\n", nResult);
    nResult += nX;
    printf("Result += %d -> %d\n", nX, nResult);
    nResult %= nX;
    printf("Result modul %d -> %d\n", nX, nResult);
    nResult /= nX;
    printf("Result /= %d -> %d\n", nX, nResult);

    nResult = 1;
    nResult <<= nX;
    printf("Result <<= %d -> %d\n", nX, nResult);
    nResult ^= nX;
    printf("Result ^= %d -> %d\n", nX, nResult);

}   /* използвайте и други оператори за присвояване */