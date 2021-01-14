#include <stdio.h>

void Naemi(float CaravanaPrice, int CaravanaSvobodni, float KemperPrice, int KemperSvobodni, int rez);
int GlavnoMenu(int Selection);

int main()
    {
        int CaravanaSvobodni = 3;
        int KemperSvobodni = 3;

        float CaravanaPrice = 90.00;
        float KemperPrice = 100.00;

        int rez=0;

        rez=GlavnoMenu(rez);
        Naemi(CaravanaPrice, CaravanaSvobodni, KemperPrice, KemperSvobodni, rez);

    }

    int GlavnoMenu(int Selection)
    {
        printf("Welcome to Unicorn Rentals - Karavani Kemperi pod naem EOOD:\n");
        printf("Jelaete li da naemete Karavana ili Kemper?\n Izberete optzia oot glavnoto menu:\n");
        printf(" 1. Karavana\n 2. Kemper\n 3. Ne jelaia naem\n");
        scanf("%d", &Selection);

       switch(Selection)
        {
            case 1:
            printf("Vie naehte Karavana za 1 den.");
            break;

            case 2:
            printf("Vie naehte Kemper za 1 den.");
            break;

            case 3:
            printf("Radvame se za poseshtenieto. Ne zabraviaite havliata za iz pat!");
            break;
        }

        return Selection;

    }

   void Naemi(float CaravanaPrice, int CaravanaSvobodni, float KemperPrice, int KemperSvobodni, int rez)
   {
       float Prihod;
       switch(rez)
       {
           case 1:
           CaravanaSvobodni--;
           Prihod=1*CaravanaPrice;
           break;

           case 2:
           KemperSvobodni--;
           Prihod=1*KemperPrice;
           break;
       }

   }