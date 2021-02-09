/*
Задача 1. Дефинирайте и инициализирайте едномерен масив с 5 елемента. 
След като сте готови, направете въвеждане на данните в масива, като четете от 
потребителя със scanf.
*/

#include <stdio.h>

void ReadArray();

int main(){
    ReadArray();

}

void ReadArray(){
    int ArrayInt[5];
    char ArrayChars[5];
    int TypeChoice = 1;
    printf("What type of elements will the Array contain?\n");
    printf("- Press 1 for integers.\n- Press 2 for characters.\n");
    scanf("%d", &TypeChoice);
    printf("Please now enter 5 elements:\n");
    switch (TypeChoice){
        case 1:
        for(int i=0; i<5; i++){
            scanf("%d", &ArrayInt[i]);
            printf("%d ", ArrayInt[i]);
        }
        break;

        case 2:
        for (int i=0; i<5; i++){
            scanf("%c", &ArrayChars[i]);
            printf("%c", ArrayChars[i]);
        }
        break;

    }


}