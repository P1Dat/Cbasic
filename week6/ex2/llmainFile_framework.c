#include <stdio.h>
#include <string.h>

#include "data_t.h"
#include "mFile.h"
#include "llist.h"

#define NOT_FOUND -1

typedef data_t T;

// TODO: 
// return index of items where p->data.name == key
int linearSearchStr(root_t root, char name2Find[]) {
  int i = 0;
  for (node_t * p = root ; p!= NULL ; p=p->next)
  {
    if (strcmp(p->data.name,name2Find) == 0) 
      return i;
    i++;
  }
  return NOT_FOUND;  // no match
}

int main() {

  const char fname[] = "test.dat";

  //nhập data từ File
  data_t a[100];
  int n = readFromFile(fname, a, 100 );

  //tạo list với data đã nhập
  root_t lst = llInit();
  for(int i=0;i<n;i++)
    lst = llInsertTail(lst,a[i]);
  showAllData(lst);
  printf("\n");

  //tìm kiếm
  int index = linearSearchStr(lst, "B");

  if (index == NOT_FOUND)
    printf("Not found\n");
  else {
    //đưa ra chỉ số thỏa mãn và data tại chỉ số đó
    //***CHỈ SỐ TÍNH TỪ 0***
    printf("Found. Index = %d\n", index);
    node_t * p = llSeek(lst,index);
    showData(p->data);
    //lưu data vào FILE
    write2File("result.dat", p , index);
    printf("\n");

    // check
    data_t buf[1];
    readFromFile("result.dat", buf, 1);
    showData(buf[0]);
  } 

  //Giải phóng bộ nhớ
  lst = llDeleteAll(lst);

  return 0;
}