#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

#define NOT_FOUND NULL

typedef data_t phoneAddr_t;

enum { FALSE = 0, TRUE };

root_t linearSearch(root_t root, const phoneAddr_t key) {
  node_t* p;
  for (p = root ; p != NULL ; p = p->next) if( llCmpData(p->data, key) ) return p; 
  return NOT_FOUND;
}

//Search for Name Field
root_t linearSearchNameField(root_t root, const phoneAddr_t key) {
  node_t* p;
  for (p = root ; p != NULL ; p = p->next) if( llCheckKeyName(p->data, key) ) return p; 
  return NOT_FOUND;
}

// compare two unordered lists list1 and list2
void verify1(root_t lst1, root_t lst2) {
  
  for (node_t* i = lst1 ; i != NULL ; i=i->next)
  {
    node_t* check = linearSearch(lst2,i->data);
    if ( check  == NOT_FOUND) showData(i->data);
  }
}

void verify2(root_t lst1, root_t lst2) {
  
  for (node_t* i = lst2 ; i != NULL ; i=i->next)
  {
    node_t* check = linearSearch(lst1,i->data);
    if ( check  == NOT_FOUND) showData(i->data);
  }
}

//check with Name field
void verify3(root_t lst1, root_t lst2) {
  
  //key: name field
  for (node_t* i = lst1 ; i != NULL ; i=i->next)
  {
    node_t* check = linearSearchNameField(lst2,i->data);
    if ( check  != NOT_FOUND) { showData(i->data); showData(check->data); printf("\n"); }
  }
}

int main() {
  root_t lst1 = llInit();
  root_t lst2 = llInit();
  phoneAddr_t aSV[] = {{"A", "1@", "01"},
                       {"B", "2@", "02"},
                       {"C", "3@", "03"},
                       {"D", "4@", "04"},
                       {"E", "5@", "05"}};

  phoneAddr_t bSV[] = {{"A", "1@", "01"},
                       {"B", "7@", "07"},
                       {"G", "G@", "10"},
                       {"D", "4@", "04"},
                       {"F", "F@", "09"}};
  
  for(int i = sizeof(aSV) / sizeof(aSV[0]) - 1; i>= 0 ; i-- ) {
    lst1 = llInsertHead(lst1, aSV[i]);
  }

  for(int i = sizeof(bSV) / sizeof(bSV[0]) - 1; i>= 0 ; i-- ) {
    lst2 = llInsertHead(lst2, bSV[i]);
  }

  printf("Data of list1:\n");
  lst1 = llPrint(lst1);
  
  printf("Data of list2:\n");
  lst2 = llPrint(lst2);

  printf("Find all records in list 1 but not in list 2:\n");
  verify1(lst1,lst2);
  printf("\n");
  printf("Find all records in list 2 but not in list 1:\n");
  verify2(lst1,lst2);
  printf("\n");
  
  printf("Finds all records in list 1 and list 2 with the same key \nbut with at least one of the other fields having different values:\n");
  verify3(lst1,lst2);
  printf("\n");

  lst1 = llDeleteAll(lst1);
  lst2 = llDeleteAll(lst2);
  printf("Released memory\n\n");

  return 0;
}