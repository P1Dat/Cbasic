#include <stdio.h>
#include "tree.h"

int main(){
    treetype root;
    makeNullTree(&root);
    if(isEmptyTree(root)) printf("Empty Tree\n");

    elmType giaithua = {'!', 0};
    elmType chia = {'/', 0};
    elmType tru = {'-', 0};
    elmType cong = {'+', 0};
    elmType a = {' ', 0};
    elmType d = {' ', 2};
    elmType b = {' ', 2};
    elmType c = {' ', 2};

    root = create_node(cong);
    root = Add_Left(&root, giaithua);
    root = Add_Left(&root->left, a);

    root = Add_Right(&root,chia);
    root = Add_Right(&root->right,d);
    root = Add_Left(&root->right,tru);
    root = Add_Left(&root->right->left,b);
    root = Add_Right(&root->left->right,c);
    
  return 0;
} 