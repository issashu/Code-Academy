/*
Задача 4.
Пренапишете Задача 2 от 05.03.2021г за Пощенските такси на дадена 
куриерска фирма се определят според тежестта на пратките (с точност до цял грам) и обема, 
както е показано в таблицата. 
При влизане в някоя функция отваряте файл за писане и при успешно излизане от функцията 
записвате във файла function_name() success . Това го правим за всички функции. Ако има 
някаква грешка записваме грешката във файла и името на функцията.
*/
#include <stdio.h>
#include <stdlib.h>

static const char* FileName = "Task4.txt";

typedef struct
{
    int weight;
    float weight_price;
    int size;
    float size_price;
    float total_price;
} packages;

void fillarr(packages *pack, int);
void checksum(packages *pack, int);

int main(void)
{
    FILE *fileptr = NULL;

    int number_of_packages;
    printf("How many packages would you want?\n");
    scanf("%d", &number_of_packages);
    packages *pack = (packages *)malloc(number_of_packages * sizeof(packages));
    fillarr(pack, number_of_packages);
    checksum(pack, number_of_packages);
    free(pack);

    fopen_s(&fileptr, FileName, "a");
    fprintf(fileptr, "Function int main(void) -> success. \n");
    fclose(fileptr);
    return 0;
}
void fillarr(packages *pack, int number)
{
    FILE *fileptr = NULL;
    fopen_s(&fileptr, FileName, "a");

    int i = 0;
    for (i = 0; i < number; i++)
    {
        printf("Enter weight in grams for package %d.\n", i + 1);
        scanf("%d", &(pack + i)->weight);
        printf("Enter size in sm for package %d.\n", i + 1);
        scanf("%d", &(pack + i)->size);
    }

    fprintf(fileptr, "Function void fillarr(packages *pack, int number) -> success. \n");
    fclose(fileptr);
}


void checksum(packages *pack, int number)
{
    FILE *fileptr = NULL;
    fopen_s(&fileptr, FileName, "a");

    float tax = 0.0;
    int i = 0;
    int total_weight = 0;
    int total_size = 0;
    float total_weight_price = 0.0;
    float total_size_price = 0.0;
    float total_individual_packages = 0.0;
    float total_all_price = 0.0;

    for (i = 0; i < number; i++)
    {
        total_weight += pack[i].weight;
        total_size += pack[i].size;
        if ((pack + i)->weight <= 20)
            pack[i].weight_price = 0.46;
        else if (pack[i].weight > 20 && pack[i].weight <= 50)
            pack[i].weight_price = 0.69;
        else if (pack[i].weight > 50 && pack[i].weight <= 100)
            pack[i].weight_price = 1.02;
        else if (pack[i].weight > 100 && pack[i].weight <= 200)
            pack[i].weight_price = 1.75;
        else if (pack[i].weight > 200 && pack[i].weight <= 350)
            pack[i].weight_price = 2.13;
        else if (pack[i].weight > 350 && pack[i].weight <= 500)
            pack[i].weight_price = 2.44;
        else if (pack[i].weight > 500 && pack[i].weight <= 1000)
            pack[i].weight_price = 3.20;
        else if (pack[i].weight > 1000 && pack[i].weight <= 2000)
            pack[i].weight_price = 4.27;
        else if (pack[i].weight > 2000 && pack[i].weight <= 3000)
            pack[i].weight_price = 5.03;
        else
            pack[i].weight_price = 5.03;
        if (pack[i].size <= 10)
            pack[i].size_price = 0.01;
        else if (pack[i].size > 10 && pack[i].size <= 50)
            pack[i].size_price = 0.11;
        else if (pack[i].size > 50 && pack[i].size <= 100)
            pack[i].size_price = 0.22;
        else if (pack[i].size > 100 && pack[i].size <= 150)
            pack[i].size_price = 0.33;
        else if (pack[i].size > 150 && pack[i].size <= 250)
            pack[i].size_price = 0.56;
        else if (pack[i].size > 250 && pack[i].size <= 400)
            pack[i].size_price = 1.5;
        else if (pack[i].size > 400 && pack[i].size <= 500)
            pack[i].size_price = 3.11;
        else if (pack[i].size > 500 && pack[i].size <= 600)
            pack[i].size_price = 4.89;
        else
            pack[i].size_price = 5.79;

        pack[i].total_price = pack[i].size_price + pack[i].weight_price;
        total_individual_packages += pack[i].total_price;
    }
    if (total_weight <= 20)
        total_weight_price = 0.46;
    else if (total_weight <= 50)
        total_weight_price = 0.69;
    else if (total_weight <= 100)
        total_weight_price = 1.02;
    else if (total_weight <= 200)
        total_weight_price = 1.75;
    else if (total_weight <= 350)
        total_weight_price = 2.13;
    else if (total_weight <= 500)
        total_weight_price = 2.44;
    else if (total_weight <= 1000)
        total_weight_price = 3.20;
    else if (total_weight <= 2000)
        total_weight_price = 4.27;
    else if (total_weight <= 3000)
        total_weight_price = 5.03;
    else
        total_weight_price = 5.03;
    if (total_size <= 10)
        total_size_price = 0.01;
    else if (total_size <= 50)
        total_size_price = 0.11;
    else if (total_size <= 100)
        total_size_price = 0.22;
    else if (total_size <= 150)
        total_size_price = 0.33;
    else if (total_size <= 250)
        total_size_price = 0.56;
    else if (total_size <= 400)
        total_size_price = 1.5;
    else if (total_size <= 500)
        total_size_price = 3.11;
    else if (total_size <= 600)
        total_size_price = 4.89;
    else
        total_size_price = 5.79;

    total_all_price = total_size_price + total_weight_price;

    if (total_all_price > total_individual_packages)
    {
        printf("Packages with weight: %d and size %d are better to be sent as separate shipments for price %.2f.\n", total_weight, total_size, total_individual_packages);
    }
    else
    {
        printf("Packages with weight %d and size %d are better to be sent as one shipment for price %.2f.\n", total_weight, total_size, total_all_price);
    }

    fprintf(fileptr, "Function void checksum(packages *pack, int number) -> success. \n");
    fclose(fileptr);
}