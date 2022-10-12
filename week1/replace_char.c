#include <stdio.h>
#include <string.h>
char* replace_char(char *str,char c1,char c2){
    int i;
    for(i=0;i<strlen(str);i++) if(str[i]==c1) str[i]=c2;
    return str;
}
int main(){
    char *str,c1,c2;
    scanf("%s%*c",str);
    scanf("%c%*c",&c1);
    scanf("%c",&c2);    
    printf("%s\n",replace_char(str,c1,c2));
    return 0;
}