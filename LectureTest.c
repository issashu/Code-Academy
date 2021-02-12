#include <stdio.h>
#include <stdlib.h>

int AllocateMemory (int uSize);
int ReallocateMemory(int *p);
int EnterElements(int *p, int MaxElem);
int FreeMemory(int *p);

int *Pointy;

int main(){
    //Variables go here:
    short NrElements = 0;

    //Methods go here:
    printf("Please enter how many elements do you need: \n");
    scanf("%d", &NrElements);
    AllocateMemory (NrElements);
    EnterElements(Pointy, NrElements);
    ReallocateMemory(Pointy);
    FreeMemory(Pointy);
}

int AllocateMemory (int uSize){
    int *Pointy = calloc(uSize, sizeof(int));   
    if (Pointy == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array allocated at %p up to %p\n", Pointy, (Pointy+uSize));
        return 0;
    }
}

int ReallocateMemory(int *p){
    int NewMax = 0;
    printf ("Please enter a new size for the array: \n");
    scanf ("%d", &NewMax);
    Pointy = realloc(p, NewMax * sizeof(int));
    if (Pointy == NULL){
        printf("I am terribly sorry, Sir! Something went wrong. Have a jolly afternoon.\n");
        return 1;
    }
    else{
        printf("Array reallocated at %p up to %p\n", Pointy, (Pointy+NewMax));
        return 0;
    }
}

int EnterElements(int *p, int MaxElem){
    printf("Please enter the desired elements of the array:\n");
    for(int i=0; i < MaxElem; i++){
        scanf("%d", &p[i]);
    }

    for(int i=0; i < MaxElem; i++){
        printf("%d ", p[i]);
    }

}

int FreeMemory(int *p){
    free(p);
}