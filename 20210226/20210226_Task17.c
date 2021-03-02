  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BroiDini 3

typedef struct{
    float Diametar;
    float Kora;
}dinia;

float randomize(int lower, int upper);
float average(dinia *Ptr);

int main(){
    srand(time(0));
    float vutreshnostA=0.0;
    float vutreshnostB=0.0;
    int upper = 35;
    int lower = 5;
    int count = 3;

    dinia *A = malloc(BroiDini*sizeof(dinia));
    dinia *B = malloc(BroiDini*sizeof(dinia));

    for (int i=0 ; i<BroiDini; i++){
        A[i].Diametar = (float) randomize (15, 140);
        B[i].Diametar = (float) randomize (35, 95);

        A[i].Kora = (float) randomize (5, 35)/10;
        B[i].Kora = (float) randomize (3, 9)/10;
    }
    /*DEBUG:
    for (int i=0 ; i<BroiDini; i++){
        printf("A Diametar: %.1f\n", A[i].Diametar);
        printf("B Diametar: %.1f\n", B[i].Diametar);
        printf("A Kora: %.1f\n", A[i].Kora);
        printf("B Kora: %.1f\n", B[i].Kora);
    }
    
    printf("%.1f\n",average(A));
    printf("%.1f\n",average(B));
    */

   vutreshnostA=average(A);
   vutreshnostB=average(B);
    if(vutreshnostA>vutreshnostB){
        printf("Its better to buy melon from sort A with average ripe interior of %.1f cm\n",vutreshnostA);
    }
    else if (vutreshnostA<vutreshnostB){
        printf("Its better to buy melon from sort B with average ripe interior of %.1f cm\n",vutreshnostB);
    }
    else {
        printf("They are equal\n");
    }

    free(A);
    free(B);
    return 0;
}

float randomize(int lower, int upper){
    float num = (rand() % (upper - lower + 1)) + lower;

    return num;
}

float average(dinia *Ptr){
    float Average = 0.00;
    float Suma = 0.00;
    float Average1 = 0.00;
    float Suma1 = 0.00;

    for (int i =0; i<BroiDini; i++){
        Suma += Ptr[i].Kora;
    }

    Average = Suma/BroiDini;

    for (int i =0; i<BroiDini; i++){
        Suma1 += Ptr[i].Diametar;
    }

    Average1 = Suma1/BroiDini;

    return Average1-Average;
}