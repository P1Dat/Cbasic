#ifndef __BST_wordcount_H__
#define __BST_wordcount_H__

typedef char* key_t;  // specify a type for the data

typedef struct data_type{
  int count;
  char word[21];
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t Search(key_t x, tree_t Root);
void insertNode(data_t x, tree_t *pRoot);
void inorderprint(tree_t tree);
void inorderprint_File(tree_t tree, FILE* const fout);
void freetree(tree_t tree);

#endif