/*
•Viết 1 chương trình đọc 2 hoặc nhiều dòng
trong 1 mảng các xâu kí tự (từng dòng 1) từ 1
file được chỉ định và tìm ra chiều dài mỗi dòng.
•Bạn fải viết độ dài dòng trước mỗi dòng trong file output.
•Ví dụ: 1 dòng trong file input là:
• The quick brown fox jumps over the lazy dog.
• Dòng này khi được ghi vào file output là:
• 44 The quick brown fox jumps over the lazy dog.
*/
#include <stdio.h> 
#include <string.h>

int main(){

    char name_file1[11],name_file2[11];
    printf("Name of input\n"); scanf("%s",name_file1);
    printf("Name of output\n"); scanf("%s",name_file2);
    FILE* f1= fopen(name_file1,"r");
    FILE* f2= fopen(name_file2,"w");
    if(f1==NULL||f2==NULL)
    {
        printf("ERORR, Can't open file !\n");
        return 0;
    }
    char str[201];
    while (fscanf(f1,"%[^\n]%*c",str)==1)
    {
        fprintf(f2,"%d %s\n",strlen(str),str);
    }    
    fclose(f1);
    fclose(f2);
    return 0;
}