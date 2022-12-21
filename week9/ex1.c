// Exercise 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

void InOrderTraversal(tree_t root){
  if (root == NULL)
   return;
 
    /* first recur on left child */
    InOrderTraversal(root->left);
 
    /* then print the data of node */
    printf("%s ", root->data.email);
 
    /* now recur on right child */
    InOrderTraversal(root->right);
}

int main() {
  tree_t tree = NULL;
  srand(time(NULL));

  // Create an binary search tree with 10 nodes.
  // Each node contains an random data.
  phoneAddr_t A[10] = { {"E","011","E@"},
                        {"D","010","D@"},
                        {"A","012","A@"},
                        {"H","022","H@"},
                        {"J","021","J@"},
                        {"B","066","B@"},
                        {"I","099","I@"},
                        {"C","032","C@"},
                        {"F","055","F@"},
                        {"G","088","G@"}    
  };

  //insert
  for(int i = 0 ; i < 10 ; i++ ) insertNode(A[i],&tree);
  
  //print bst's nodes in inorder
  InOrderTraversal(tree);

  //free  
  freeTree(tree);

  return 1;
}