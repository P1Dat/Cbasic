/*
• Cài đặt hàm my_strcat :
– Đầu vào – 2 xâu, s1 và s2
– Đầu ra – con trỏ tới xâu nối cấp phát
động
–Ví dụ: Xâu nối của “hello_” và “world!”
là xâu “hello_world!”

• Kiểm tra hàm của bạn
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* my_strcat(char *str1, char *str2){
    int len1, len2; 
    len1 = strlen(str1); 
    len2 = strlen(str2);
    char *str = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (str == NULL) {
        printf("fail!\n");
        return NULL;
    }
    strcpy(str, str1);
    strcpy(str + len1, str2);
    return str;
}

int main(){
    char s1[101],s2[101];
    printf("Enter the first string:\n");
    scanf("%s",s1);
    printf("Enter the second string:\n");
    scanf("%s",s2);
    printf("%s\n",my_strcat(s1,s2));
    return 0;
}