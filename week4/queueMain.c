#include "queue.h"
#include <stdio.h>
int main(){
    Queue q;
    int i;
    initialize(&q);
    for(i=0 ; i<10 ; i++)
        EnQueue(i,&q);
    for(i=0 ; i<10 ; i++)
    {
        int x = DeQueue(&q);
        printf("%d ",x);
    }
    return 0;
}