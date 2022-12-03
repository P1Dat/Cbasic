#include <stdio.h>
#include "mFile.h"

//Ghi dữ liệu của một node ra File
void write2File(const char fname[],node_t* p, const int n){
    FILE *fout = fopen(fname,"wb");
    if(fout == NULL ) printf("ERROR FILE !\n");
    else fwrite(&p->data,sizeof(data_t),1,fout);
    fclose(fout);
}

// Trả về số phần tử đọc được
// Dữ liệu được chứa trong buf, buf phải được cấp phát trước ngoài hàm
int readFromFile(const char fn[], data_t buf[], int elemSize){
    int i = 0;
    FILE *fin = fopen(fn,"rb");
    if(fin == NULL ) printf("ERROR FILE\n");
    else
        while ( fread(&buf[i],sizeof(data_t),1,fin) )
        {
            i++;
            if(i==elemSize) break;
        }
    fclose(fin);
    return i;
}