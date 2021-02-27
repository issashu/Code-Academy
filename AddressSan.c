#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __attribute__((__packed__)){
    char Produkt[50];
    float Tzena;
    uint16_t Kolichestvo;
} smetka;


int main(int argc, char **argv) {
    smetka Shokolad;
    Shokolad.Tzena = 2.50;
    strcpy(Shokolad.Produkt, "shokolad");
	int stack_array[10];
    int t = 3;
	stack_array[100] = 10;
    printf("Please enter how much %s you want to buy (in grams):\n", Shokolad.Produkt);
    scanf("%d", &Shokolad.Kolichestvo);
    t>>23;
    printf("For the %d gramms of %s, the price would be %.2f leva\n", Shokolad.Kolichestvo, Shokolad.Produkt, (Shokolad.Tzena*(Shokolad.Kolichestvo/100)));
  	printf("The total whole items of type %s in inventory are: %d",Shokolad.Produkt, stack_array[100]);
  	return 0;
}

/*

*/clang -O1 -g -fsanitize=address -fsanitize=shift -fno-omit-frame-pointer AddressSan.c