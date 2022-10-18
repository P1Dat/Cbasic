/*
• A)Cải thiện chương trình trong bài tập trước để
nó nhận vào 2 tên file từ tham số dòng lệnh.

• Ví dụ: nếu chương trình của bạn đặt tên là
"filecpy". Có thể dùng cú pháp sau (trên Linux):
• ./filecpy haiku.txt haiku2.txt

• B. Viết chương trình có cùng tính năng với lệnh
cat trong Linux
• ./cat1 haiku.txt
*/

#include <stdio.h>
void mycpy(FILE* fin , FILE* fout){
    char str[101];
    int num;
    while(!feof(fin)){
        num = fread(str,sizeof(char),101,fin);
        str[num*sizeof(char)] = '\0';
        fwrite(str,sizeof(char),num,fout);
    }
    fclose(fin);
    fclose(fout);
}
void mycat(FILE* fin){
    char str[101];
    int num;
    while(!feof(fin)){
        num = fread(str,sizeof(char),101,fin);
        str[num*sizeof(char)] = '\0';
        printf("%s",str);
    }
    fclose(fin);
}
int main(int argc, char *argv[]){

    if(argc>3 || argc < 2) {
        printf("FAILE!");
        return 0;
    }

    if(argc==3){
    FILE* f1= fopen(argv[1],"r");
    FILE* f2= fopen(argv[2],"w");
    if(f1==NULL||f2==NULL)
    {
        printf("ERORR, Can't open file !\n");
        return 0;
    }
    mycpy(f1,f2);
    fclose(f1);
    fclose(f2);
    }
    else 
    if(argc==2){
        FILE* f1= fopen(argv[1],"r");
        if(f1==NULL)
        {
            printf("ERORR, Can't open file !\n");
            return 0;
        }
        mycat(f1);
    fclose(f1);
    }
    return 0;
}