/*• Viết chương trình để nhập vào vài số từ luồng vào tiêu
chuẩn và xuất ra file “out.txt” theo thứ tự ngược lại. Thêm
vào đó, xuất tổng các số vào cuối file out.txt.
• Khuôn dạng dữ liệu nhập vào từ luồng vào tiêu chuẩn là
như sau: số đầu tiên là số lượng dữ liệu, số thứ 2 trở đi là
dữ liệu để tính toán.Ví dụ khi nhập vào:
4 12 -45 56 3

• “4” là só con số theo sau nó, và phần còn lại “12 -45 56 3”
sẽ là các số được xuất ra file “out.txt” . Dữ liệu xuất ra
“out.txt” là:
3 56 -45 12 26

• Con số cuối cùng “26” là tổng của 4 số trước đó.
• Ví số lượng con số nhập vào thay đổi theo mỗi lần chạy chương trình, bạn sẽ phải phân phối bộ nhớ động cho số
lượng dự liệu: sử dụng hàm malloc( ).
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *ptr;
    int *p;
    int i=0,n,x,sum=0;
    printf("enter numbers:\n"); scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int)) ;
    for(i=0;i<n;i++)
    {
        scanf("%d", &x);
        p[i]=x;
        sum+=x;
    }
    if ((ptr=fopen("out.txt","w")) == NULL )
    {
        printf("FAILE!!!\n");
        return 0;
    }
    for ( i = n-1 ; i >= 0; i--)
    {
        fprintf(ptr,"%d ",p[i]);
    }
    fprintf(ptr,"%d",sum);
    fclose(ptr);
    free(p);
    return 0;
}
