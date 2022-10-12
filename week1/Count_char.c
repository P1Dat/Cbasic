//Viết chương trình nhập vào một xâu ký tự và hiển thị số lần xuất.
//hiện của mỗi ký tự có trong xâu.
#include <stdio.h>
#define ALPHABET_LEN 26
int main(){
    char c='\0';
    int count[ALPHABET_LEN];
    int i;
    for(i=0;i<26;i++) count[i]=0;  
    c=getchar();
    while(c!='\n'&&c>=0)
    {
        if('a'<=c && c<='z')  count[c-'a']++;
        else
        if('A'<=c && c<='Z')  count[c-'A']++;
        c=getchar();
    }
    for(i=0;i<26;i++) if(count[i]>0)
    {
        printf("The letter '%c' appears %d time(s).\n",i+'a',count[i]);
    }
    return 0;
}