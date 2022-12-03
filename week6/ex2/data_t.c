#include <stdio.h>
#include "data_t.h"

//In ra dữ liệu một node
void showData(data_t data) { 
  printf("%s - %s - %s\n", data.name, data.tel, data.email);
}

//In ra toàn bộ list
void showAllData( root_t root ) {
  for (node_t* p = root; p != NULL; p=p->next) {
    showData(p->data);
  }
}