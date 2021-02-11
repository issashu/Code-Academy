/*
Задача 2. Напишете програма, която чете съобщение, след което го принтира в обратен ред:
Enter a message: I am Miro.
Reversal is : .oriM ma I
Използвайте getchar() за да вземете символите от конзолата, запазете ги в масив от чарове, 
прекратете четенето до достигане на \n. Използвайте пойнтер, който да сочи към текущата позиция на масива. 
Чрез него принтирайте масива в обратен ред.
*/

#include <stdio.h>

int main(){
    char array[20]={'s'};
    char *pointy = array;
    char c = 0;
    short counter = 0;
    
    printf("Please enter a message {only 20 characters will be read from buffer]:\n");
    while((counter < 20) &&  (c != '\n')){
        array[counter] = c;
        ++counter;
        c = getchar();
    }

    for (int i=counter; i>=0; i--){
        printf("%c", pointy[i]);
    }

    /* DEBUG: 
    for(int i = 0; i<counter; i++)
        printf("%c", array[i]);
    */
}