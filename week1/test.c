#include<stdio.h>
#include<string.h>



/* write a function that:
  –gets a string and two chars–the functions scans the string and replaces every occurrence of the first char with the second one. */



void  str(char *s , char a, char b, int n){
  int i=0;
  while(i<n)
    {
      if(*s==a) {*s=b;}
      s++;
      i++;
    }
  return  ;
}



int main(){
  char s[1000];
    char a,b;
  printf("Enter string: ");
  scanf("%s",s);
   printf("%s",s);
  printf("Enter character a: ");
  scanf("%*c%c",&a);   
//   printf("%c",a);
  printf("Enter character b: ");
  scanf("%*c%c",&b);   
//   printf("%c",b);
  str(s,a,b,strlen(s));
  printf("%s",s);
  printf("\n");
  return 0;
}