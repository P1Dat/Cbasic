// +Viết 1 hàm nhận vào 1 số kiểu
// double. Hàm cho kết quả phần nguyên
// và phần thập phân của số đó.
// + Viết chương trình nhận vào 1 số từ
// người sử dụng. Áp dụng hàm trên.
#include <stdio.h>
int solve(double *num){
    int ans = (int) *num;
    *num -= ans;
    return ans;
}
int main(){
    double num;
    scanf("%lf",&num);
    printf("%d\n",solve(&num));
    printf("%lf\n",num);
    return 0;
}