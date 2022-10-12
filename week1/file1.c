// + Tạo 1 file lab1.txt với nội dung tuỳ ý.
// + Viết 1 chương trình đọc từng kí tự của
// file trên rồi ghi vào file lab1w.txt
#include <stdio.h>
int main(){
    char name_file1[11] = "lab1.txt";
    char name_file2[11] = "lab1w.txt";
    FILE* f1= fopen(name_file1,"r");
    FILE* f2= fopen(name_file2,"w");
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