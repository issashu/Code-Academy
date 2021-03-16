/*
Задача 5. Да се напише рекурсивен вариант на
функцията за обхождане на двоично дърво.
*/
#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task5.h"

/**
 * @brief The app fills in 5 binary trees, one for each array
 *        as per the task requirements
 * 
 * @return int 
 */
int main(){
    key=root;
    int ArrayOne[] = {7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13};
    int Data = 0;

    for (int i=0; i<13; i++){
        AddNode(&root,ArrayOne[i]);
    }

    printf("What are ye lookin' for?");
    scanf("%d", &Data);
    SearchNode(key,Data);

}
//======================================================================
/**
 * @brief Creates a Tree root object
 * 
 * @param root - a pointer to the global root
 */
void CreateTreeNode(Tnode** Node, int Data){
    (*Node) = (Tnode*)malloc(sizeof(Tnode*));
    (*Node)->Left = NULL;
    (*Node)->Right = NULL;
    (*Node)->NodeValue = Data;
}

/**
 * @brief Adds Node to the tree based on value
 * 
 * @param root 
 * @param Data 
 */

void AddNode (Tnode** Node, int Data){
    if((*Node)==NULL){
        CreateTreeNode(Node, Data);
    }
    else{
        if (Data<(*Node)->NodeValue){
            AddNode(&(*Node)->Left, Data);
            //-> =(*).
        }
        else if(Data>(*Node)->NodeValue){
            AddNode(&(*Node)->Right, Data);
        }
    }
}

void SearchNode(Tnode** key, int Data){
    if((*key)==NULL){
        printf("No tree to sniff! Awwoooowww!\n");
        exit(1);
    }
    else{
        if (Data<(*key)->NodeValue){
            SearchNode((*key)->Left, Data);
            //-> =(*).
        }
        else if(Data>(*key)->NodeValue){
            SearchNode((*key)->Right, Data);
        }
        else if (Data==(*key)->NodeValue){
            printf("I climbed the tree and found the leaf at address %p and the value was %d", &(*key), (*key)->NodeValue);
        }
    }
}