// •Thực thi 1 hàm nhận vào 2 mảng số
// nguyên, trả về 1 nếu 2 mảng giống
// nhau, trả về 0 nếu không.
// •Viết 1 chương trình nhận 2 mảng số
// nguyên từ người sử dụng và kiểm tra
// sự = nhau.
#include <stdio.h>
int check(int A[], int n, int B[], int m){
    int i;
    if(n!=m) return 0;
    for(i=0;i<n;i++) if(A[i]!=B[i]) return 0; 
    return 1;
}

int main(){
    int A[101],B[101],n,m,i;
    printf("Nhap so phan tu mang 1: \n");
    scanf("%d",&n);
    printf("Nhap cac phan tu mang 1: \n");
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    printf("Nhap so phan tu mang 1: \n");
    scanf("%d",&m);
    printf("Nhap cac phan tu mang 1: \n");
    for(i=0;i<m;i++) scanf("%d",&B[i]);
    printf("anwser is \n%d\n",check(A,n,B,m));
    return 0;
}