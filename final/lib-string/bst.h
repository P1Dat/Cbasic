#ifndef __BST_H__
#define __BST_H__

typedef struct data_s{
    /*---------------------fix------------------------*/
    int type;
    char key[12];  //------> this is KEY !
    /*------------------------------------------------*/
} data_t;

typedef struct node_s {
    
    data_t data;
    struct node_s *left, *right;
} node_t;

typedef node_t *tree_t;

//--- specify a type for the data ---
typedef char key_t; //-------> type of KEY ! 

tree_t treeInit();

void showDataOfNode(data_t tree);

tree_t makeTreeNode(data_t item);
tree_t Search(key_t x[], tree_t Root);
void Insertnode_t(data_t x, tree_t *pRoot);

tree_t findMin(tree_t *Root);
tree_t findMax(tree_t *Root);

key_t* DeleteMin(tree_t *Root);
void Deletenode_t(key_t x[], tree_t *Root);

void freetree(tree_t tree);

void printInorder(tree_t tree);
void printPreorder(tree_t tree);
void printPostorder(tree_t tree);

void f_printInorder(tree_t tree, FILE* f);

#endif