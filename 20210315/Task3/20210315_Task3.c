/*
Задача 3. Да се построи наредено двоично дърво за
търсене чрез последователно добавяне на следните
върхове:
а) 7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13
б) 12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65
в) 4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81
г) 81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4
д) 28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14
Да се сравнят получените дървета. Какви изводи могат
да се направят?
*/

#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task3.h"

int main(){
    int ArrayOne[] = {7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13};
    int ArrayTwo[] = {12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65};
    int ArrayThree[] = {4, 7, 12, 13, 14, 18, 28, 35, 42, 61, 64, 65, 81};
    int ArrayFour[] = {81, 65, 64, 61, 42, 35, 28, 18, 14, 13, 12, 7, 4};
    int ArrayFive[] = {28, 64, 13, 42, 7, 81, 61, 4, 12, 65, 35, 18, 14};

    for (int i=0; i<13; i++){
        AddNode(&root,ArrayOne[i]);
    }
    
    for (int i=0; i<13; i++){
        AddNode(&root2,ArrayOne[i]);
    }

    for (int i=0; i<13; i++){
        AddNode(&root3,ArrayOne[i]);
    }

    for (int i=0; i<13; i++){
        AddNode(&root4,ArrayOne[i]);
    }

    for (int i=0; i<13; i++){
        AddNode(&root5,ArrayOne[i]);
    }
}

/* void PrintTree(Tnode** From) {
    int branches = 1;
    Tnode **cur = From, **next;
    do {
        for (int i = branches; i > 0; i++) {
            printf("%d ", *cur->data);
            
        }
    }
} */
/*    if(root->key < val)
        root->right = insert(root->right,val);
   
    else if(root->key > val)
        root->left = insert(root->left,val);
*/