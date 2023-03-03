# lib-string

Libraries are enhanced by using `string` variables as `keys`

## llist.h

```sh
#ifndef __LLIST_H__
#define __LLIST_H__

#include <string.h>

typedef struct data_s{
    /*---------------------fix------------------------*/
    int type;
    char key[12];  //------> this is KEY !
    /*------------------------------------------------*/
} data_t;


typedef struct node_s {
    
    data_t data;
    struct node_s *next;
} node_t, *root_t;


root_t llInit();
node_t* llCreateNewNode(const data_t data);
void llShowData(data_t data);
root_t llPrint(root_t root);

root_t llInsertHead(root_t root, const data_t data);
root_t llInsertTail(root_t root, const data_t data);
root_t llInsertAfter(root_t root, node_t* prev_node, const data_t data);

root_t llDeleteHead(root_t root);
root_t llDeleteTail(root_t root);
root_t llDeleteAfter(root_t root, node_t* prev_node);
root_t llDeleteAll(root_t root);

int llLength(root_t root);
root_t LLReverse(root_t root);
node_t* llSeek(root_t root, int index);

#endif
```
## bst.h

```sh
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
```
## hash.h

```sh
#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>


/*---------------------fix------------------------*/
#define MAX_CHAR (11)
#define TABLE_SIZE (13)
/*------------------------------------------------*/

enum { FALSE, TRUE };//0---1


typedef struct data_s{
    /*---------------------fix------------------------*/
    int type;
    char key[MAX_CHAR];  //------> this is KEY !
    /*------------------------------------------------*/
} data_t;

typedef struct node_t {
  data_t data;
  struct node_t* next;
} element_t;

void init_table(element_t* ht[]);
int hash(const char *key);

void htShowData(data_t data);

element_t* findElement(element_t* ht[], char key[]);
int insertItem(element_t* ht[], element_t o);
int removeElement(element_t* ht[], char key[]);

int isEmpty(element_t* ht[]);

void clear(element_t* ht[]);

void traverse(element_t* ht[]);  // Duyet

void _traversebucket(element_t *ht[], int b);

void clearbucket(element_t *ht[], int b);
void clear(element_t *ht[]);

#endif

```

# Usage

You can use `test.c` to test libraries with `DATA` in file `test.txt` 

## Step 1: Unlock `test.c`

In `test.c`: 
- Unlock the library which you want to test. For example, I want to test hash.h:

```sh
//=========Select lib=======
// #include "bst.h"
// #include "llist.h"
#include "hash.h"
```
- Then, unlock the code of hash table:

```sh
   /*============================ TEST HASH TABLE ==========================*/

    // printf("Test HASH:\n");
    // init_table(ht);

    // printf(">>>>Init HASH:\n");
    // while (!feof(f)){
    //     data_t newData;
    //     fscanf(f,"%s %d",newData.key,&newData.type);
    //     element_t e;
    //     e.data = newData;
    //     e.next = NULL;
    //     insertItem(ht, e);
    //     printf("(key, hash(key)) = (%s, %d)\n", newData.key ,hash(newData.key) );
    // }

    // printf("\n\n>>>>HASH:\n");
    // traverse(ht);

    // printf("\n\n>>>>Du lieu tim duoc:\n");
    // element_t *p = findElement(ht, "valverde");
    // if(p!=NULL) htShowData(p->data);

    // printf("\n\n>>>>>>HASH sau khi xoa:\n");
    // removeElement(ht, "valverde");
    // removeElement(ht, "vinicius");
    // removeElement(ht, "musiala");
    // traverse(ht);
    // clear(ht);
    
    /*=======================================================================*/  
```

## Step 2: Fix

In libraries ( lib.h or lib.c ), codes that are commented as `fix` should be edited depending on the topic. For example, the `data_t` in the following hash.h need to be changed according to requirements, or the `TABLE_SIZE` will not be enough and needs to be increased.

```sh
/*---------------------fix------------------------*/
#define MAX_CHAR (11)
#define TABLE_SIZE (13)
/*------------------------------------------------*/

enum { FALSE, TRUE };//0---1


typedef struct data_s{
    /*---------------------fix------------------------*/
    int type;
    char key[MAX_CHAR];  //------> this is KEY !
    /*------------------------------------------------*/
} data_t;

typedef struct node_t {
  data_t data;
  struct node_t* next;
} element_t;

```

## Step 3: Compile

### If you don't use `makefile`

```sh
gcc -c lib.c
gcc -c test.c
gcc -o test.o lib.o
```

### If you use `makefile`

In makefile.mak, you can set up follow:

```sh
main: test.o lib.o
	gcc -o a test.o lib.o

test.o: test.c lib.h
	gcc -c test.c

lib.o: lib.c lib.h
	gcc -c lib.c
```

> NOTE: `lib.h` is the library which you want to test, for example `hash.h`
Then, you just use `make` in cmd, and use `.\a` to run program
