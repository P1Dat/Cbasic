// BST: Bin Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

tree_t Search(key_t x, tree_t Root) {
  if (Root == NULL)
    return NULL;           // not found
  else if (strcmp(Root->data.word , x ) == 0 ) /* found x */
    return Root;
  else if (strcmp( Root->data.word , x ) < 0 ){
    // continue searching in the right sub tree
    return Search(x, Root->right);
  }
  else 
  {
    // continue searching in the left sub tree
    return Search(x, Root->left);
  }
}

void insertNode(data_t x, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    memcpy(&((*pRoot)->data), &x, sizeof(data_t));  // <===
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp(x.word, (*pRoot)->data.word) < 0)  // <===
    insertNode(x, &((*pRoot)->left));
  else if (strcmp(x.word, (*pRoot)->data.word) > 0)  // <===
    insertNode(x, &((*pRoot)->right));
}

void inorderprint(tree_t tree) {
  if (tree != NULL) {
    inorderprint(tree->left);
    printf("%s %d\n", tree->data.word,tree->data.count);
    inorderprint(tree->right);
  }
}

void inorderprint_File(tree_t tree, FILE* const fout) {
  if (tree != NULL) {
    inorderprint_File(tree->left,fout);
    fprintf(fout,"%s %d\n", tree->data.word,tree->data.count);
    inorderprint_File(tree->right,fout);
  }
}

void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}