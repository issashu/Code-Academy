#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BaseConverter(char *Number, int *Base);


int main()
{
   int Base=2;
   char Number=(255+10);
   
   BaseConverter(&Number, &Base);

}

void BaseConverter(char *Number, int *Base)
{
   int *Result;
   int Iterate=0;
   Result=(int*)calloc(4000, sizeof(int));   //Not sure how to simulate std::vector in C. Now less then 1 MB
   while (*Number>0)
        {
            (Result[Iterate])= *Number%*Base;
            Iterate++;     
            *Number/=*Base;
        }
   
        printf ("The number in base %d is:\n", *Base);
        for(int i=(Iterate-1); i>=0; i--)
        {
            //Prints in DEC numerals. Don't know how to enable HEX numerals.
            printf("%d",Result[i]);
        }

   free(Result);
}