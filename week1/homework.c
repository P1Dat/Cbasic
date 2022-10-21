#include <stdio.h>
void solve(FILE *fin){
    char c;
    int i=2;
    printf("1 ");
    while((c=fgetc(fin))!=EOF){
        if(c=='\n') printf("%c%d ",c,i++);
        else printf("%c",c);
    }    
    return;
}
int main(int argc, char* argv[]){
    if(argc != 2)
    {   
        printf("ERROR !\n");
        printf("Correct syntax: <file to run> <file source>\n");
        return 0;
    }
    FILE* f1 = fopen(argv[1],"r");
    if(f1==NULL){
        printf("ERROR: can't open file %s\n",argv[1]);
        return 0;
    }
    solve(f1);
    fclose(f1);
    return 0;
}