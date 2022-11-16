#include <stdio.h>
#include "stack.h"
int main(){
    StackType s;
    initialize(&s);
    int i;
    for(i=0;i<10;i++)
    {
        push(i,&s);
    }
        
    for(i=0;i<10;i++)
    {
        Eltype e = pop(&s);
        printf("%d ",e);
    }
    return 0;
}
//cmd
//lenh tao stack.o
//gcc -c stack.c 
//lenh tao stackMain.o
//gcc -c stackMain.c
//lenh lien ket va tao mainTest de chay
//gcc -o mainTest stackMain.o stack.o