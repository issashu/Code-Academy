/*
Задача 3. Използвайте Задача 1. за да напишете програма, която проверява дали съобщението не е палиндром. 
Палиндром е съобщение, в което буквите от ляво на дясно са същите като от дясно на ляво.
I did, did I?
*/

#include <stdio.h>

int main(){
    char array[10] = {'s'} ;
    char *pointy = array;
    short counter = 0;
    char c = 0;
    int start = 0;
    int end = 0;
    
    //tested qwerewq
    printf("Please enter a string (max 10 characters will be read from buffer): \n");
    scanf("%[^\n]%*c", &array);

    /*while((counter < 10) &&  (c != '\n')){
        array[counter] = c;
        ++counter;
        c = getchar();
    }*/
    
    end = counter;
    
    while (end > start){
        if (*(pointy+start) != *(pointy+end)){
            printf("String is not palindrome");
            return 0;
        }
        start++;
        end--;
    }
    printf("The string is palindrome");
}

