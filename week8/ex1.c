/*
–return the height of a binary tree.
–return the number of leafs
–return the number of internal nodes
–count the number of right children.
*/
#include <stdio.h>
#include "tree.h"



int treeHeight(treetype root){
    if (root == NULL) 
        return 0;
    else {
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);   
        return ( ( left_height > right_height ) ?  left_height + 1 : right_height + 1 ) ;
    }
}

int treeNbrLeaf(treetype root){
    if(root == NULL)	
	    return 0;
    if(root->left == NULL && root->right==NULL)	
	    return 1;			
    else
	    return treeNbrLeaf(root->left) + treeNbrLeaf(root->right);	
}

int treeInternalNode(treetype root){
    return nb_nodes(root) - treeNbrLeaf(root) - 1;
}

int treeNbrRightChildren(treetype root) {
        if(!root)  // tree does not exist.
            return 0;

        // tree exists...now see if R node exits or not.
        if(root->right) // right node exist

            // return 1 + # of R children in L/R subtree.
            return 1 + treeNbrRightChildren(root->right) + treeNbrRightChildren(root->left);

        else // right nodes does not exist.
            // total count of R children will come from left subtree.
            return treeNbrRightChildren(root->left);
}

int main(){
    treetype root;
    makeNullTree(&root);
    if(isEmptyTree(root)) printf("Empty Tree\n");

    for(int i=0;i<10;i++)
        Add_Left(&root,10+i);
    for(int i=0;i<5;i++)
        Add_Right(&root,100+i);
    printf("Tree height: %d\n",treeHeight(root));
    printf("So la: %d\n",treeNbrLeaf(root));
    printf("# internal node: %d\n",treeInternalNode(root));
    printf("# right children: %d\n",treeNbrRightChildren(root));
    return 0;
}