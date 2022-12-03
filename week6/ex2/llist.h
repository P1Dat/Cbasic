#ifndef __LLIST_H__
#define __LLIST_H__

#include "data_t.h"
root_t llInit();
node_t* createNewNode(const data_t data);
root_t llInsertHead(root_t root, const data_t data);
root_t llInsertTail(root_t root, const data_t data);
root_t llDeleteAll(root_t root);
node_t* llSeek(root_t root, int index);
#endif