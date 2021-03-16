#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task3.h"


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