#include<stdio.h>
#define MAX_LEN 80
int main ()
{
   FILE *f1,*f2;
   char str[MAX_LEN+1];
   int num;
   f1 = fopen( "lab1.txt " , "r" );
   f2 = fopen( "lab1w.txt" , "w" );
   while (!feof(f1))
   {
        num = fread(str, sizeof(char) , 1, f1);
        //printf("%d %d\n",sizeof(char),num);
        str[num*sizeof(char)]='\0';
        fwrite(str , sizeof(char) , 1, f2 );
   }
   fclose(f1); 
   fclose(f2); 
   return(0);
}