#include <stdio.h>

//Memory is read in chunks of 1,2,4 or 8 based on biggest size of variables.
//Everything smaller is padded, as in gets empty bytes in order to be the same size as the biggest
//This optimises speed of reading data at the cost of more memory taken.
//32bit CPUs can get 4 bytes at once to read, 64bit can get 8 bytes at once.
//With padding we give them chunks that they can read at once and thus speed up the program

struct tagTestA{
    char m_ch;
    short int m_si; 
};

//Removes extra padding - aka removes the empty bytes done in order to set all types to same size

struct tagTestAP{ 
    char m_ch; 
    short int m_si;
} __attribute__((packed)); 

int main(){
    printf("sizeof(A) = %d, sizeof(A-packed) = %d\n", sizeof(struct tagTestA), sizeof(struct tagTestAP));
    return 0; 
}