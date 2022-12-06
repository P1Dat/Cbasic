#ifndef __LLIST_H__
#define __LLIST_H__

#include <string.h>

// ==================================================================
// Must Adapt to new problem
// ==================================================================
typedef struct phoneAddr_s {
  char name[20];
  char tel[20];
  char email[32];
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

void showData(const data_t data);

// ==================================================================
root_t llPrint(root_t root);

root_t llInit();
node_t *llSeek(root_t root, int index);

root_t llInsertHead(root_t root, const data_t data);
root_t llInsertTail(root_t root, const data_t data);
root_t llInsertAfter(root_t root, node_t *pAElem, const data_t data);

root_t llDeleteHead(root_t root);
root_t llDeleteTail(root_t root);
root_t llDeleteAfter(root_t root, node_t *pA);
root_t llDeleteAll(root_t root);

// Tools
int llCmpData(data_t x, data_t y);
int llCheckKeyName(data_t x, data_t y);

#endif