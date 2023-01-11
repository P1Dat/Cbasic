#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "bst.h"

void String_upper(char s[]){
    int i;
    for(i=0;i<strlen(s);i++) s[i] = toupper(s[i]);
    return ;
}

int check_Char(char key){
    if( ('a'<=key&&key<'z') || ('A'<=key&&key<='Z') || ('0'<=key&&key<='9') )
        return 1;
    return 0;
}

int main(int argc, char *argv[]){

    if( argc != 3 ){
        printf("ERROR SYNTAX ! \n  Correct Syntax: wordcount input.txt output.txt\n");
        return 0;
    }

    FILE *fin  = fopen(argv[1],"r");
    if( fin == NULL ){
        printf("ERROR: can't open file input !\n");
        return 0;
    }

    FILE *fout = fopen(argv[2],"w");
    if( fout == NULL ){
        printf("ERROR: can't open file output !\n");
        return 0;
    }

    tree_t tree = NULL;

    char readChar = '\0';
    
    while( fscanf(fin,"%c",&readChar) != EOF ){

        char tmp[101] = "\0";

        if( check_Char(readChar) ){
            if( !(strlen(tmp)) ) tmp[0] = readChar ; 
                else tmp[strlen(tmp)] = readChar ;
        }
        else continue;
        
        while(  fscanf(fin,"%c",&readChar) != EOF && check_Char(readChar) ){

            if( !(strlen(tmp)) ) tmp[0] = readChar ; 
                else tmp[strlen(tmp)] = readChar ;
        }
        
            String_upper(tmp);
            tree_t pointer_search = Search(tmp, tree);

            if( pointer_search == NULL ){

                data_t tmp_data;
                strcpy(tmp_data.word,tmp);
                tmp_data.count = 1;
                insertNode(tmp_data, &tree);

            }
            else{
                pointer_search->data.count++;
            }
        
    }

    inorderprint_File(tree,fout);

    freetree(tree);

    fclose(fin);
    fclose(fout);

    return 0;
}