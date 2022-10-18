/*• Giả sử ta tạo ra danh bạ điện thoại.
• Định nghĩa một kiểu dữ liệu có thể lưu giữ
"name," "telephone number," "e-mail
address,” và tạo ra mảng các cấu trúc có
thể lưu giữ nhiều nhất 100 dữ liệu.
• Nhập 10 dữ liệu vào mảng này.
• Viết một chương trình để ghi nội dung
mảng đã nhập liệu vào file, sử dụng fwrite() và dùng hàm fread ( ) để đọc dữ
liệu từ mảng.
*/
#include <stdio.h>
#include <string.h>
typedef struct 
{
    char name[21];
    char tele[11];
    char mail[21];
} infor ; 

int main(){
    int i;
    int n=10;
    infor A[101];
    for(i=0;i<n;i++){
        printf("Person %d\n",i+1);
        printf("Enter name: \n");
        scanf("%[^\n]%*c",A[i].name);
        printf("Enter telephone: \n");
        scanf("%[^\n]%*c",A[i].tele);
        printf("Enter e-mail: \n");
        scanf("%[^\n]%*c",A[i].mail);
    }
    FILE* fout = fopen("phonebook.txt","w");
    if(fout==NULL)
    {
        printf("FAILE!");
    }
    char endline[1]="\n";
    char space[1] = " ";
    for(i=0;i<n;i++){
        fwrite(A[i].name, sizeof(char), strlen(A[i].name), fout);
        fwrite(space, sizeof(char), 1, fout);
        fwrite(A[i].tele, sizeof(char), strlen(A[i].tele), fout);
        fwrite(space, sizeof(char), 1, fout);
        fwrite(A[i].mail, sizeof(char), strlen(A[i].mail), fout);
        fwrite(endline, sizeof(char), 1, fout);
    }
    fclose(fout);

    FILE* fin = fopen("phonebook.txt","r");
    if(fin==NULL)
    {
        printf("FAILE!");
    }
    char str[101];
    int num;
    for(i=0;i<n;i++){
        num = fread(str,sizeof(char),101,fin);
        str[num*sizeof(char)] = '\0';
        printf("%s\n",str);
    }
    fclose(fin);
    return 0;
}