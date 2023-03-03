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
