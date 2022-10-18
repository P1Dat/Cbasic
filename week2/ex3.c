// • Viết một chương trình sử dụng các
// thao tác khối với file để sao chép nội
// dung file lab1.txt tới lab1a.txt
// • Dùng: fread, fwrite, feof
#include <stdio.h>
void DataBlock(FILE *f1, FILE *f2){
    int num;
    char str[101];
    while (!feof(f1)){
        num = fread(str, sizeof(char) , 101, f1);
        //printf("%d %d\n",sizeof(char),num);
        str[num*sizeof(char)]='\0';
        fwrite(str , sizeof(char) , num, f2 );
    }
    fclose(f1);
    fclose(f2);
}

int main() {
    char name_file1[11] = "lab1.txt";
    char name_file2[11] = "lab1w.txt";
    FILE* f1= fopen(name_file1,"r");
    FILE* f2= fopen(name_file2,"w");
    if(f1==NULL||f2==NULL)
    {
        printf("ERORR, Can't open file !\n");
        return 0;
    }
    DataBlock(f1,f2);
    fclose(f1);
    fclose(f2);
    return 0;
}
