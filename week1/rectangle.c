/*
+ Viết chương trình nhận vào 2 số dưới
dạng tham số dòng lệnh, biểu diễn
chiều dài và chiều rộng của 1 hình chữ
nhật.(số ở dưới dạng dấu phẩy động).
+ Chương trình đưa ra diện tích và chu
vi của hcn.*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    if(argc != 3){
         printf("ERROR SYNTAX ! \n");
         printf("corret syntax: RECT <HEIGHT> <WEIGHT>");
         return 0;
    }
    double height = atof(argv[1]);
    double weight = atof(argv[2]);
    printf("area: %0.2f\n",height*weight);
    printf("perimeter: %0.2f\n",2*(height+weight));
    return 0;
}