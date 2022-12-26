//count word by using binary search tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

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

void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}


int main(){
    
    //tree init
    tree_t tree = NULL;
    srand(time(NULL));

    //solve init
    char c = '\0' ;
    scanf("%c",&c);

    //solve
    while(c!='\n' && c!='.')
    {

        char s[21] = "\0";

        //read the word
        while( ('a'<=c&&c<='z') || ('A'<=c&&c<='Z') ){
          c = toupper(c); 
          if(!(strlen(s))) s[0] = c;
          else s[strlen(s)] = c;
          scanf("%c",&c);
        }
        
        //when have the word ---> check it !
        if(c == ' ' || c == '.' || c == '\n' ) {

          //pointer search  
          tree_t p = NULL;
          p = Search(s,tree);

          //not found ---> insert
          if(p==NULL) { 
            data_t x;
            strcpy(x.word,s);  
            x.count = 1;
            insertNode(x,&tree);
          }
          else p->data.count++; //found ---> count++
        }
        scanf("%c",&c);
    }

    inorderprint(tree);
    //free tree
    freetree(tree);
    return 0;
}
