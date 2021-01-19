#include <stdio.h>

int isLetter (char c);

int main()
{
    char c = 'a';
    printf("Please enter a character: ");
    scanf("%c", &c);
    isLetter(c);

    return 0;
}

int isLetter (char c)
{
    //using https://www.ascii-code.com
    if ((c >= 65 && c<=90) || (c>=97 && c<=122))
        printf("The enter character is a letter.\n");
    else
        printf("The entered character is not a letter.\n");

}