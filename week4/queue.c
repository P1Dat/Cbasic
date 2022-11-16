#include "queue.h"
#include <stdlib.h>
void initialize(Queue *pQ){
    pQ->Front=-1;
    pQ->Rear=-1;
}
int Empty_Queue(Queue Q){
    return Q.Front==-1;
}
int Full_Queue(Queue Q){
    return (Q.Rear-Q.Front+1)==MaxLength;
}
void EnQueue(ElementType X,Queue *pQ){
    if (!Full_Queue(*pQ)){
        if (Empty_Queue(*pQ)) pQ->Front=0;
        pQ->Rear=pQ->Rear+1;
        pQ->Elements[pQ->Rear]=X;
    }
    else printf("Queue Full!");
}
ElementType DeQueue(Queue *pQ){
    if (!Empty_Queue(*pQ)){
        ElementType retVal=pQ->Elements[pQ->Front];
        pQ->Front=pQ->Front+1;
        if (pQ->Front > pQ->Rear)
        initialize(pQ);
        return retVal;
    }
    else printf("Queue empty!");\
    exit(-1);
}