#ifndef __STACK_H__ //chu ky
#define __STACK_H__

#include <stdio.h>

#define MAX 50
typedef int Eltype;
typedef struct StackRec {
    Eltype storage[MAX];
    int top;
} StackType;

void initialize(StackType *pStack);
int empty(StackType stack);
int full(StackType stack);
void push(Eltype el, StackType *pStack);
Eltype pop(StackType *Stack);
#endif

