#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Base=1;
int Number=0;
int *Result;
int Counter=3999;
 

char Rerun='y';

int NumberSelection(int *Number)
{
   printf("Please enter a number to convert:\n");
   scanf("%d", &Number);
   while (Number>32767)  //Says warning comparison pointer and int, but segmentation fault crash if derreferenced
    {
      printf("Please enter an INT number to convert:\n");
      scanf("%d", &Number);
    }
   
   return Number;
}

int BaseSelection()
{
       int Selection;
       printf("Please select a base numerical system to conver to:\n");
       printf(" 1.DEC\n 2.OCT\n 3.BIN\n 4.HEX\n");
       scanf("%d", &Selection);
   
       while(Selection<1 || Selection>4) //Missing validation of non-numeric characters
       {
         printf("Please select an entry from 1 to 4 only:\n");
         scanf("%d", &Selection);
       }

       switch (Selection)
       {
          case 1:
          {
             printf("The number in base 10 is: %d \n", Number);
             return 0;
          }
          case 2:
          {
             Base=8;
             break;
          }
          case 3:
          {
             Base=2;
             break;
          }
          case 4:
          {
             Base=16;
             break;
          }
       }
   return Base;
}

void BaseConverter(int *Number, int *Base)
{
   int Iterate=0;
   Result=(int*)calloc(4000, sizeof(int));   //Not sure how to simulate std::vector in C. Now less then 1 MB
   while (*Number>0)
        {
            (Result[Iterate])= *Number%*Base;
            Iterate++;     
            *Number/=*Base;
        }
   
        printf ("The number in base %d is:\n", Base);
        for(int i=(Iterate-1); i>=0; i--)
        {
            //Prints in DEC numerals. Don't know how to enable HEX numerals.
            printf("%d",Result[i]);
        }

        free(Result);
}

int main()
{
   
   Number=NumberSelection(&Number);
   Base=BaseSelection();   
        
   //User selected number and base to convert to.
   //Following are calculations and convertion left in main,not separate function call
   
   BaseConverter(&Number, &Base);

}