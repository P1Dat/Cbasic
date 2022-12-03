#include <stdio.h>
#include <string.h>

#include "data_t.h"
#include "mFile.h"

#define NOT_FOUND -1


// TODO: 
// return index of items where items[index] == key
int linearSearchStr(data_t items[], int siz, char name2Find[]) {
  int i;  
  for (i=0 ; i<siz ; i++)
    if ( strcmp(items[i].name,name2Find) == 0) 
      return i;
  return NOT_FOUND;  // no match
}

int main() {
  const char fname[] = "test.dat";
  data_t a[100];
  
  int n = readFromFile(fname, a, 100 );
  showAllData(a, n);
  printf("\n");

  int index = linearSearchStr(a, n , "B");
  
  if (index == NOT_FOUND)
    printf("Not found\n");
  else {
    printf("Found. Index = %d\n", index);
    showData(a[index]);
    write2File("result.dat", a , index);
    printf("\n");

    // check
    data_t buf[1];
    readFromFile("result.dat", buf, 1);
    showData(buf[0]);
  }  

  return 0;
}