#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bst.h"


tree_t treeInit(){
  return NULL;
}

void showDataOfNode(data_t data){
    /*-------------------------------fix---------------------------*/
    printf("%s&%d\n",data.key,data.type);
    /*-------------------------------------------------------------*/
}

tree_t makeTreeNode(data_t item)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t*));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

tree_t Search(key_t x[], tree_t Root) {
    if (Root == NULL)
        return NULL;           // not found
    else if (strcmp(Root->data.key, x)==0) /* found x */
        return Root;
    else if (strcmp(Root->data.key, x)<0)
        // continue searching in the right sub tree
        return Search(x, Root->right);
    else {
        // continue searching in the left sub tree
        return Search(x, Root->left);
    }
}

void Insertnode_t(data_t x, tree_t *pRoot){
    if (*pRoot == NULL) {
        /* Create a new node for key x */
        *pRoot = (node_t *)malloc(sizeof(node_t));
        (*pRoot)->data = x;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
    }else if (strcmp ( x.key , (*pRoot)->data.key ) < 0)
    Insertnode_t(x, &((*pRoot)->left));
    else if ((x.key , (*pRoot)->data.key) > 0 )
    Insertnode_t(x, &((*pRoot)->right));
}

key_t* DeleteMin(tree_t *Root) {
    char key[12];
    char *k = key;
    if ((*Root)->left == NULL) {
        strcpy(key,(*Root)->data.key);
        (*Root) = (*Root)->right;
        
        return k;
    } else
    return DeleteMin(&(*Root)->left);
}

void Deletenode_t(key_t x[], tree_t *Root) {
    if (*Root != NULL)
    if (strcmp(x , (*Root)->data.key) < 0 )
        Deletenode_t(x, &(*Root)->left);
    else if (strcmp(x, (*Root)->data.key) > 0 )
        Deletenode_t(x, &(*Root)->right);
    else if (((*Root)->left == NULL) && ((*Root)->right == NULL))
        *Root = NULL;
    else if ((*Root)->left == NULL)
        *Root = (*Root)->right;
    else if ((*Root)->right == NULL)
        *Root = (*Root)->left;
    else 
        strcpy((*Root)->data.key,DeleteMin(&(*Root)->right)); 
}

void printInorder(tree_t tree)
{
    if (tree == NULL)
        return;
 
    /* first recur on left child */
    printInorder(tree->left);
 
    /* then print the data of node */
    showDataOfNode(tree->data);
    
    /* now recur on right child */
    printInorder(tree->right);
}

void printPreorder(tree_t tree)
{
    if (tree == NULL)
        return;

    /* first print data of node */
    showDataOfNode(tree->data);    
 
    /* then recur on left subtree */
    printPreorder(tree->left);
 
    /* now recur on right subtree */
    printPreorder(tree->right);
}

void printPostorder(tree_t tree)
{
    if (tree == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(tree->left);
 
    // then recur on right subtree
    printPostorder(tree->right);
 
    // now deal with the node
    showDataOfNode(tree->data);   
}
 

void f_printInorder(tree_t tree, FILE* f)
{
    if (tree == NULL)
        return;
 
    /* first recur on left child */
    f_printInorder(tree->left,f);
 
    /* then print the data of node */
    showDataOfNode(tree->data);
 
    /* now recur on right child */
    f_printInorder(tree->right,f);
}


tree_t findMin(tree_t *Root){
    if (*Root==NULL) return NULL;
    else{
        if((*Root)->left==NULL) return *Root;
        else return(findMin(&(*Root)->left));
    }
}

tree_t findMax(tree_t *Root){
    if (*Root==NULL) return NULL;
    else{
        if((*Root)->right==NULL) return *Root;
        else return(findMax(&(*Root)->right));
    }
}

void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}