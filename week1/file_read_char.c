/*
• Tạo 1 file lab1.txt với nội dung tuỳ ý.
• Viết 1 chương trình đọc từng kí tự của
file trên rồi ghi vào file lab1w.txt
*/
#include <stdio.h>
int main(){
    FILE *f1 = fopen("lab1.txt", "r");
    FILE *f2 = fopen("lab1w.txt","w");   
    if(f1==NULL||f2==NULL) {
        printf("Can't open file !");
        return 0;
    }
    char c;
    while ((c=fgetc(f1)) != EOF){
        fprintf(f2,"%c",c); 
        putchar(c);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
// #include <stdio.h>
// enum {SUCCESS, FAIL};

// void CharReadWrite(FILE *fin, FILE *fout)
// {
// int c;
// while ((c=fgetc(fin)) != EOF){
// fputc(c, fout); /* write to a file */
// putchar(c);
// /* display character on the screen */
// }
// }


// int main() {
// FILE *fptr1, *fptr2;
// char filename1[]= "lab1w.txt";
// char filename2[]= "lab1.txt";


// if ((fptr1 = fopen(filename1, "w")) == NULL){
// printf("Cannot open %s.\n", filename1);
// } else if ((fptr2 = fopen(filename2, "r")) == NULL){
// printf("Cannot open %s.\n", filename2);
// } else {
// CharReadWrite(fptr2, fptr1);
// fclose(fptr1);
// fclose(fptr2);
// }
// return 0;
// }