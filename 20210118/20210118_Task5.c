#include <stdio.h>

int main() {
    int x = 1, y = 0; // Two separate expressions
    int z = y || x; // z = 1
    
    //X will be 1 and Y will be 0
    printf("\nInit values: X= %d, Y= %d\n", x, y); 

    //Only first expression will be calculated and X = 3
    x = 1 + 2, 2 * 3, 3 + 4;
    
    //All expressions will be calculated and Y will become the last one = 5
    y = ( 7 * 8, 8 + 9, 9 - 4);
    
    //X will be 3 and Y will be 5
    printf("\nX= %d, Y= %d\n", x, y);
    return 0; 
}
 