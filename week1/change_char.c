// +Viết 1 hàm:
// - hận 1 xâu và 2 kí tự.
// - Hàm quét toàn bộ xâu và thay kí tự thứ nhất mỗi lần nó
// xuất hiện trong xâu bởi kí tự thứ 2.

// +Viết 1 chương trình để test hàm trên. Đầu vào
// do người sử dụng nhập, xâu kí tự không có dấu
// khoảng trống. In ra xâu kết quả.
// +Example:
// – input: “papa”, ‘p’, ‘m’
// – output: “mama”
#include <stdio.h>
#include <string.h>
void solve(char str[], char c1, char c2){
    int i;
    for(i=0;i<strlen(str);i++) if (str[i]==c1) str[i]=c2;
    printf("%s\n",str);
    return;
}
int main(){
    char str[101],c1,c2;
    scanf("%s%*c",str);
    scanf("%c%*c",&c1);
    scanf("%c",&c2);
    solve(str,c1,c2);
    return 0;
}