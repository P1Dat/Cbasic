/*
• Viết chương trình đọc 1 file text được tạo
bởi emacs (ví dụ emacs abc.txt), thêm số
thự tự của dòng vào trước mỗi dòng trong file output. Tên file text được nhập vào dưới
dạng đối số của hàm main.
• Ví dụ: file input:
This is sample file.
Hello!
• Nội dung file output:
1 This is sample file.
2 Hello!
*/

#include <stdio.h>
int main(int argc, char *argv[]){
    char name_file1[11],name_file2[11];
    printf("Name of input\n"); scanf("%s",name_file1);
    FILE* f1= fopen(name_file1,"r");
    FILE* f2= fopen(argv[1],"w");
    if(f1==NULL||f2==NULL)
    {
        printf("ERORR, Can't open file !\n");
        return 0;
    }
    char str[201]; int i=1;
    while (fscanf(f1,"%[^\n]%*c",str)==1)
    {
        fprintf(f2,"%d %s\n",i++,str);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}