#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "Hi";
    int StrLenght = 0;
    for (int i=0; i<(sizeof (s)/sizeof(s[0])); i++)
    {
        printf ("%c", s[i]);
        if(s[i]!='\0')
            StrLenght ++ ;
    }
    printf ("\n The lenght of s is %d elements!\n", StrLenght);


    /* USING STRLEN
    char DouglasAdams[]="The Answer to the Great Question... Of Life, the Universe and Everything... Is... Forty-two - said Deep Thought, with infinite majesty and calm.";
    int Life = strlen(DouglasAdams);
    printf ("%d\n", Life);
    */

}