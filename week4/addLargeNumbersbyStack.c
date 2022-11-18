/*
Author: Phung Tien Dat - 20210163
Finish day: 11/19/2022
The program will add two very large numbers
*/
#include <stdio.h>
#include "stack.h"

int main(){
    StackType s1;
    initialize(&s1);
    StackType s2;
    initialize(&s2);
    StackType result;
    initialize(&result);

    char c='\0';
    printf("Enter the first number:\n");
    while(1){
        scanf("%c",&c);
        if(c=='\n') break;
        push(c,&s1);
    }
    printf("Enter the second number:\n");
    while(1)
    {
        scanf("%c",&c);
        if(c=='\n') break;
        push(c,&s2);
    }

    int remember = 0;
    while(!(empty(s1)||empty(s2)))
    {   
        Eltype e1;
        Eltype e2;

        if(empty(s1)) e1 = 48;
    else
        e1 = pop(&s1);

        if(empty(s2)) e2 = 48;
    else
        e2 = pop(&s2);

        int tmp = e1 - 48 + e2 - 48 + remember;

        if( tmp  >= 10 )
        {
            remember = 1;
            tmp -= 10;
            push(tmp + 48, &result);
        }
    else
        {
            remember = 0;
            push(tmp + 48, &result);
        }
    }
    if(remember) push( 1 + 48, &result);
    printf("Result is: \n");
    while(!empty(result))
    {
        Eltype e = pop(&result);
        printf("%c",e);
    }
    return 0;
}
