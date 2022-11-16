#include "stack.h"
void initialize(StackType *pStack){
    (*pStack).top = 0 ;
}
int empty(StackType stack){
    return stack.top==0;
}
int full(StackType stack){
    return stack.top==MAX;
}
void push(Eltype el, StackType *pStack){
    if(full(*pStack)) printf("Stack overflow\n");
    else
    (*pStack).storage[(*pStack).top++] = el;
}
Eltype pop (StackType *pStack){
    if(empty(*pStack)) printf("stack underflow\n");
    else
    return (*pStack).storage[--(*pStack).top];
}
