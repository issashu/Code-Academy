/*
Направете програма за изчисляване на баркод UPC(Universal Product Code)
Производителите на стоки от години поставят баркодове на своите продукти. Всеки баркод представлява 12 числа:
Първото число е типа на продукта
Лявата група числа представят производителя,
Дясната група числа представят продукта
Последното число е за проверка.

0 13800 15173 5

Ето алгоритъма за изчисление на проверката за грешка:
Съберете нечетните числа: първото, третото, петото и т.н.
Съберете четните числа: второто, четвъртото и т.н
Умножете първата сума по 3 и добавете втората сума.
Извадете 1 от тотала
Делите тотала по модул на 10.
Изваждате резултата от 9 и трябва да получите последната цифра.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int BarcodeChecksum(int *barcode);

int main(){
int barcode[12];
int Resulcheck=0;

printf("Please enter the UPC Barcode and hit Enter\n:");
printf("Keep in mind that:\n");
printf(" 1.Barcode is of the 12 digits type.\n 2.Enter digits from left to right.\n 3.Only first 12 digits entered will be read.\n");

for (int i=0;i<12;i++)
   {
       int c = getchar();
       if ((c < '0') || (c > '9'))
       {
           printf("invalid digit!");
           printf("Please start the application again and be carefull.\n");
           exit(0);
       }
       barcode[i] = c;
   }
   for (int i=0; i<12; i++){
       printf("%c", barcode[i]);
   }

printf("\nCalculating Barcode checksum: ...\n");
sleep(1);
Resulcheck = BarcodeChecksum(barcode);

if(Resulcheck == barcode[11]){
    printf("Barcode is OK. Bye!");
}else{
    printf("Barcode not Ok. Bye!");
}
}

int BarcodeChecksum(int *barcode){
    int SumOdd = 0;
    int SumEven = 0;
    int CheckSum = 0;

    for (int i=0; i<12; i++){
        if (i%2!=0){
            SumOdd+=barcode[i];
        }
        if(i%2==0){
            SumEven+=barcode[i];
        }
    }

    
    CheckSum = ((((SumOdd*3)+SumEven)-1)%10);
    
    for (int i=0; i<12; i++){
       printf("%c", barcode[i]);
   }
    printf("%d\n", SumOdd);
    printf("%d\n", SumEven);
    printf("%d\n", CheckSum);
    printf("%d\n", (9-CheckSum));
    
    
}