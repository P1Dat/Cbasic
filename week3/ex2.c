/*
• Tạo hàm insert, delete với tham số n (nguyên)
chỉ ra vị trí của node bị tác động đến.
• Vị trí đầu tiên là 0
• n = 1: thêm phần tử vào sau phần tử đầu tiên.
• n = 2: thêm phần tử vào sau phần tử thứ 2.

struct AddressList *insert (struct AddressList
*root, struct Address ad, int n);

struct AddressList *delete(struct AddressList
*root, int n);
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char name[256];
    char phone[256];
    char email[256];
    struct Node *next;
} addressList;
addressList *head, *tail;
void initList(){
    head = NULL;
    tail = NULL;
}
int listEmpty(){
    return head == NULL && tail == NULL;
}
void printList(){
    for(addressList* p = head; p != NULL; p = p->next)
    printf("%s, %s, %s\n",p->name, p->phone, p->email);
}

//Thêm Node vào cuối danh sách
void insertTail(char* name, char* phone, char* email){
    addressList* p = makeNode(name,phone,email);
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
    addressList* p = makeNode(name,phone,email);
    if(listEmpty()){
        head = p;
        tail = p;
    }else{
        p->next = head;
        head = p;
    }
}

struct addressList* insert(struct AddressList* root, int n){
    
}

int main(){
    return 0;
}



/*
void RemoveNode(SingleList &list, int d){
  Node *pDel = list.pHead; // tạo một node pDel để xóa
  //Nếu pDel == Null thì danh sách rỗng
  if(pDel == NULL){
    cout<<"Danh sách rỗng!!";
  }
  //ngược lại thì xét điều kiện
  else{
    Node *pPre = NULL;
    //dùng vòng lặp while để tìm ra pDel và pPre (vị trí đứng trước pDel)
    while(pDel != NULL){
      if(pDel -> data == d){
        break;
      }
      pPre = pDel;
      pDel = pDel -> pNext;
    }
    //Nếu pDel == null tức là không tìm thấy số cần xóa
    if(pDel == NULL){
      cout<<"Không tìm thấy số cần xóa";
    }
    // Ngược lại tiếp tục xét điều kiện
    else{
      // Nếu pDel == list.pHead, tức là số cần xóa ở đầu danh sách
      if(pDel == list.pHead){
        list.pHead = list.pHead -> pNext;
        pDel -> pNext = NULL;
        delete pDel;
        pDel = NULL;
      }
      //Nếu pDel == list.pTail, tức là số cần xóa ở cuối danh sách
      else if(pDel -> pNext == NULL){
        list.pTail = pPre;
        pPre -> pNext = NULL;
        delete pDel;
        pDel = NULL;
      }
      // và trường hợp cuối cùng số muốn xóa nằm ở giữa danh sách
      else{
        pPre -> pNext = pDel -> pNext;
        pDel -> pNext = NULL;
        delete pDel;
        pDel = NULL; 
      }
    }
  }
}*/