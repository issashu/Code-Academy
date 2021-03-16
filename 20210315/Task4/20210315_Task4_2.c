#include <stdio.h>
#include <stdlib.h>
#include "20210315_Task4.h"


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
            //-> ==(*).
        }
        else if(Data>(*Node)->NodeValue){
            AddNode(&(*Node)->Right, Data);
        }
    }
}

void RemoveNode(Tnode* key, int Data){
    Tnode* Daddy = (Tnode*) malloc (sizeof(Tnode*));
    key=root;
    do{
        Daddy = key;
        if (Data<key->NodeValue){
           key = key->Left;
           if(key==NULL){
               printf("No such element.");
           }
        }
        else if(Data>key->NodeValue){
            key = key->Right;
            if(key==NULL){
               printf("No such element.");
           }
        }
    }while(key->NodeValue!=Data);

    if(Daddy->Left!=NULL && Daddy->Left->NodeValue==key->NodeValue){
        key = Daddy->Left;
        Daddy->Left = NULL;
        printf("Deleting the entry located at address %p and with value %d\n", &key, key->NodeValue);
        free(key);
    }
    else if (Daddy->Right!=NULL && Daddy->Right->NodeValue==key->NodeValue){
        key = Daddy->Right;
        Daddy->Right = NULL;
        printf("Deleting the entry located at address %p and with value %d\n", &key, key->NodeValue);
        free(key);
    }
}