/*
 6. Напишете функция, която получава указател към масив с числа и връща 
 най-голямото от тях.
*/

#include <stdio.h>

int HighestNumber (int *s);

int main(){
    int MaxNumber = 0;
    int Numbers[5];

    printf("Please enter 5 numbers: \n");
    for (int i=0; i<5; i++){
        scanf("%d", &Numbers[i]);
    }
    
    MaxNumber = HighestNumber(Numbers);

    printf("Highest number in the array is: %d\n", MaxNumber);

}

int HighestNumber (int *s){
    int i, j = 0;
    int tmp = 0;
    
    for (i = 0; i < 5; ++i) {
        for (j = i + 1; j < 5; ++j){
            if (s[i] > s[j]) {
                tmp =  s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
    return s[j-1];
}