/*
• Ta thiết kế “address list”(danh sách
địa chỉ) cho các số điện thoại di động
• Phải tạo 1 cấu trúc gồm có name,
phone number và email address.
• Phải tạo 1 chương trình có thể giải
quyết với số lượng dữ liệu tuỳ ý
*/
//  (tiếp)

/* 
l Tạo 1 danh sách liên kết đơn chứa danh
sách phone address.
l Viết 1 hàm insert 1 phần tử vào list ngay
sau phần tử hiện thời, sử dụng nó để thêm
node vào list
l Viết 1 hàm duyệt toàn bộ list và in ra
thông tin chứa trong nó.
l Viết hàm xoá 1 node khỏi list.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct Node{
    char name[256];
    char phone[256];
    char email[256];
    struct Node *next;
} address_list;

address_list *head, *tail;

//tạo Node
address_list *makeNode(char* name, char* phone, char* email){
    address_list * p = (address_list*)malloc(sizeof(address_list));
    strcpy(p->name,name);
    strcpy(p->phone,phone);
    strcpy(p->email,email);
    p->next = NULL;
    return p; 
}
//Khởi tạo
void initList(){
    head = NULL;
    tail = NULL;
}

//Kiểm tra danh sách trống
int listEmpty(){
    return head == NULL && tail == NULL;
}

//In danh sách.
void printList(){
    system("cls");
    for(address_list* p = head; p != NULL; p = p->next)
    printf("%s, %s, %s\n",p->name, p->phone, p->email);
    getch();
}

//Thêm Node vào cuối danh sách
void insertTail(char* name, char* phone, char* email){
    address_list* p = makeNode(name,phone,email);
    if(listEmpty()){
        head = p; 
        tail = p;
    }else{
        tail->next = p; 
        tail = p;
    }
}

//Thêm Node vào đầu danh sách
void insertHead(char* name, char* phone, char* email){
    address_list* p = makeNode(name,phone,email);
    if(listEmpty()){
        head = p;
        tail = p;
    }else{
        p->next = head;
        head = p;
    }
}

//Thêm Node vào danh sách  ( đầu hoặc cuối ? )
void Insert(){
    system("cls");
    printf("Enter Name Phone email\n");
    scanf("\n");
    char name[256], phone[256], email[256];
    scanf("%s %s %s",&name,&phone,&email);
    char c;
    printf("(H)ead or (T)ail ?\n");
    scanf("\n");
    scanf("%c",&c);
    if(c=='H' || c=='h') insertHead(name,phone,email);
    else if(c=='T' || c=='t') insertTail(name,phone,email);
    else printf("!FAIL!\n");
}

address_list* removeNode(address_list* f, char* name){
    if(listEmpty()) return NULL;
    if(strcmp(f->name,name) == 0){
        address_list* tmp = f->next;
        free(f);
        if(tmp == NULL) tail = NULL;
        return tmp;
    }else{
        f->next = removeNode(f->next,name);
        return f;
    }
}

void Remove(){
    system("cls");
    printf("Which of Name do you want to Remove ?:\n");
    scanf("\n");
    char name[256];
    scanf("%s",name);
    head = removeNode(head,name);
}
int main(){
    initList();
    while (1)
    {
        printf("1 to Insert.\n");
        printf("2 to printList.\n");
        printf("3 to Remove.\n");
        printf("other to exit.\n");
        char key = getch();
        if(key=='1') Insert();
        else if(key=='2') printList();
        else if(key=='3') Remove();
        else return 0;
    }
}