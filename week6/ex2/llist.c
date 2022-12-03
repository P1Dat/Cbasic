#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

//Khởi tạo list
root_t llInit() { return NULL; }

//Tạo node
node_t* createNewNode(const data_t data) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL) return NULL;

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

//Chèn node mới vào đầu
root_t llInsertHead(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);
  pNewNode->next = root;
  return (root_t)pNewNode;
}

//Chèn node mới vào sau
root_t llInsertTail(root_t root, const data_t data) {
  node_t* pNewNode = createNewNode(data);

  if (root == NULL) return (root_t)pNewNode;

  node_t* p = NULL;
  for (p = root; p->next != NULL; p = p->next)
    ;
  p->next = pNewNode;
  return root;
}

//Giải phóng list
root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

//Trả về con trỏ tại vị trí index
//***CHỈ SỐ TÍNH TỪ 0***
node_t* llSeek(root_t root, int index) {
  node_t* p;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}