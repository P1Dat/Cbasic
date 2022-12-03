#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef struct {
  char name[20], tel[20], email[32];
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;


void showData(data_t data);
void showAllData( root_t root );

#endif