/*
•Viết chương trình đọc từng kí tự từ 1
file được chỉ định.
•Các chữ cái hoa được chuyển thành
chữ thường và ngược lại. Viết kết quả
vào 1 file mới.
•Lưu ý : ngoài các chữ cái ra thì các kí
tự khác vẫn được giữ nguyên.
*/
#include <stdio.h>
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
    char c;
    while ((c=fgetc(f1))!=EOF)
    {
        if('a'<=c&&c<='z') c-=32;
        else if('A'<=c&&c<='Z') c+=32;
        fprintf(f2,"%c",c);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}