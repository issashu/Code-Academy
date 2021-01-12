#include <stdio.h>
#include <stdbool.h>

void BoolOpertations(int Number, int Index);

int main()
{
    unsigned int Number = 0;
    int Position = 0;

    printf("Please enter a number:\n");
    scanf("%d", &Number);

    printf("Please enter an index for bit operations:\n");
    scanf("%d", &Position);

    BoolOpertations(Number, Position);

    /* Za da imame i v main kod

    printf("Number before bit change %d\n", Number);
    Number ^= (0x1 << Index);//Ex.: 1072 will become 5168 and 5168 will become 1072 if we set bit 12
    printf("Number after bit change %d\n", Number);
    printf("The bit at position %d is: %d", Index, (Number >> Index) & 0x1);  */
         
}

void BoolOpertations(int Number, int Index)
{
       int Selection;
       printf("Please select a bitwise operation: \n");
       printf(" 1.SET\n 2.CLEAR\n 3.TOGGLE\n");
       scanf("%d", &Selection);
   
       while(Selection<1 || Selection>3) 
       {
         printf("Please select an entry from 1 to 3 only:\n");
         scanf("%d", &Selection);
       }

       switch (Selection)
       {
          case 1:
          {
            printf("Number before bit change %d\n", Number);
            Number |= (0x1 << Index);//Ex.: 1072 will become 5168 if we set bit 12
            printf("Number after bit change %d\n", Number);
            printf("The bit at position %d is: %d", Index, (Number >> Index) & 0x1);
            break;
          }
          case 2:
          {
            printf("Number before bit change %d\n", Number);
            Number &= ~(0x1 << Index);//Ex.: 48 will become 16 if we clear bit 5
            printf("Number after bit change %d\n", Number);
            printf("The bit at position %d is: %d", Index, (Number >> Index) & 0x1);
             break;
          }
          case 3:
          {
            printf("Number before bit change %d\n", Number);
            Number ^= (0x1 << Index);//Ex.: 1072 will become 5168 and 5168 will become 1072 if we set bit 12
            printf("Number after bit change %d\n", Number);
            printf("The bit at position %d is: %d", Index, (Number >> Index) & 0x1);
            break;
          }
          default:
          {
            printf("You did not make a valid selection. Goodbye!\n");            
            break;
          }
       }
}