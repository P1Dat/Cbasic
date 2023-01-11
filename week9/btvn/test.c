#include <stdio.h>
int f(int i, FILE * fp){
   if(i>1) f(i+1,fp) 
}
int main(){

    FILE* fp = fopen("output.txt","w");
    
    return 0;
}