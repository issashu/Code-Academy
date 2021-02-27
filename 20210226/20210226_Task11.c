#include <stdio.h>
#include <stdlib.h>

typedef struct *t_PointStr;

typedef struct node{
    int va1 =0;
    t_PointStr PointerStruct;
}node;

int main(){
    t_PointStr Pointer = (*t_PointStr) malloc(sizeof(*t_PointStr));
}