#include <stdio.h>
#include <stdlib.h>
int main(){
    int *a, *b;
    a = (int*)malloc(10*sizeof(int));
    b = (int*)calloc(10,sizeof(int));
    int i;
    for(i=0;i<10;i++) printf("%d ",a[i]);
    printf("\n");
    for(i=0;i<10;i++) printf("%d ",b[i]);
    b = (int*)realloc(b,10*sizeof(int));
    printf("\n");
    for(i=0;i<20;i++) printf("%d ",b[i]);
    free(a);
    free(b);
    return 0;
}