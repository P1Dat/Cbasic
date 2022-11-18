/*
Author: Phung Tien Dat - 20210163
Finish day: 11/19/2022
The program uses the link list to manage student information 
and run tests on the given topic requirements, specifically:
    • Tạo một mảng 5 sinh viên với dữ liệu cho trước: 
        data_t student[] = { {"001", "sv1", 3}, {"002", "sv2", 5}, .... };
    • Tạo một danh sách liên kết từ mảng dữ liệu này bằng cách gọi hàm tương ứng vừa viết ở trên.
    • Hiển thị nội dung danh sách liên kết chứa thông tin các nut 
    • Di chuyển đến nut thứ 3
    • Xóa nút trước
    • Xóa nút sau
    • Hiển thị lại nội dung của danh sách sinh viên
    • Hiển thị nội dung danh sách liên kết chứa thông tin các sinh viên
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[11];
    char name[101];
    int grade;
} data_t;

typedef struct node_s {
    data_t data;
    struct node_s *next;
    struct node_s *prev;
} node_t, *root_t;

/*
!!!Requirement function!!!
Initialize list
*/
root_t dlInit() { return NULL; }

/*
Show data
    with: root is the pointer to the first node of the list
*/
void showData(data_t data) { 
    printf("%s %s %d\n",data.id,data.name,data.grade); 
}

/*
!!!Requirement function!!!
Print out all of nodes
    with: root is the pointer to the first node of the list
*/
root_t dlPrint(root_t root) {
    node_t *p, *q, *tmp;
    for ( p = root; p != NULL; p = p->next) {showData(p->data);if(p!=NULL) tmp=p;}
    printf("\n");
    return root;
}

/*-----------------------Insert-----------------------*/

/*
Create new node
    with: data is information of student
*/
node_t* createNewNode(const data_t data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/*
!!!Requirement function!!!
Insert node in the header with: 
    pHead is the pointer to the first node of the list
    data is information of student 
*/
root_t dlInsertHead(root_t pHead, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (pHead == NULL) return (root_t)pNewNode;
    pHead->prev = pNewNode;
    pNewNode->next = pHead;
    return (root_t)pNewNode;
}

/*
!!!Requirement function!!!
Insert node in the tail with: 
    root is the pointer to the first node of the list
    data is information of student 
*/
root_t dlInsertTail(root_t root, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (root == NULL) return (root_t)pNewNode;
    node_t* p = NULL;
    for (p = root; p->next != NULL; p = p->next) ;
    p->next = pNewNode;
    pNewNode->prev = p;
    return root;
}

/*
!!!Requirement function!!!
Add an element after an element pointed to by p in the list with:
    root is the pointer to the first node of the list
    pAElem is p
    data is information of student 
*/
root_t dlInsertAfter(root_t root, node_t *pAElem, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (pAElem == NULL) return root;
    pNewNode->prev = pAElem;
    pNewNode->next = pAElem->next;
    pAElem->next = pNewNode;
    if(pNewNode->next!=NULL)
        pNewNode->next->prev = pNewNode;
    return root;
}

/*
!!!Requirement function!!!
Add an element before an element pointed to by p in the list:
    root is the pointer to the first node of the list
    pAElem is p
    data is information of student 
*/
root_t dlInsertBefore(root_t root, node_t *pAElem, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (pAElem == NULL) return root;
    pNewNode->next = pAElem;
    pNewNode->prev = pAElem->prev;
    pAElem->prev = pNewNode;
    if(pNewNode->prev!=NULL)
        pNewNode->prev->next = pNewNode;
    return root;
}

/*
solve insertion node, with:
    root is the pointer to the first node of the list
    data is information of student
*/
root_t dlInsertStudent(root_t root, data_t data){
    node_t* pNewNode = createNewNode(data);
    node_t* prev;
    if(root==NULL){
        root = dlInsertHead(root,data);
        return root;
    }
    node_t* p ;
    for (p = root; p != NULL; p = p->next){
        if(data.grade > p->data.grade && p==root){
            root = dlInsertHead(root,data);
            return root;
        }
    else
        if(data.grade > p->data.grade){
            root = dlInsertAfter(root,prev,data);
            return root;
        }
    else
        if(p->next==NULL){
            root = dlInsertTail(root,data);
            return root;
        }
    prev=p;
    } 
    return root;
}

/*--------------------Delete--------------------------*/

/*
!!!Requirement function!!!
Delete node in the header with: 
    root is the pointer to the first node of the list
*/
root_t dlDeleteHead(root_t root){
    if (root == NULL) return NULL;
    node_t* p = root->next;
    p->prev = NULL;
    free(root);
    return (root_t)p;
}

/*
!!!Requirement function!!!
Delete node in the tail with: 
    root is the pointer to the first node of the list
*/
root_t dlDeleteTail(root_t root){
    if (root == NULL) return NULL;
    if (root->next == NULL) {
        free(root);
        return NULL;
    }
    node_t* p;
    for (p = root; p->next->next != NULL; p = p->next) ;
    free(p->next);
    p->next = NULL;
    return (root_t)root;
}

/*
!!!Requirement function!!!
Delete the element pointed to by the pointer pAElem with:
    root is the pointer to the first node of the list
    pAElem is pointer;
*/
root_t dlDelete(root_t root, node_t* pAElem){
    if (pAElem == NULL) return root;
    pAElem->prev->next = pAElem->next;
    pAElem->next->prev = pAElem->prev;
    free(pAElem);
    return root;
}

/*
!!!Requirement function!!!
Delete the entire lis with:
    root is the pointer to the first node of the list
*/
root_t dlDeleteAll(root_t root){
    node_t* p = NULL;
    for (; root != NULL; root = p) {
        p = root->next;
        free(root);
    }
    return NULL;
}

/*------------------------------find-------------------------*/
/*
Find the node, with:
    root is the pointer to the first node of the list
    index is node's order
*/
node_t* dlSeek(root_t root, int index) {
  node_t* p;
  index--;
  for (p = root; index > 0 && (p != NULL); index--) p = p->next;
  return p;
}

int main(){
    root_t lst = dlInit();
    data_t student[] = { {"001", "sv1", 3}, {"002", "sv2", 5}, {"003","sv3",6},{"004","sv4",8},{"005","sv5",10} };
    printf("Array created!!!\n\n");

    int i;
    for(i=0;i<5;i++) lst = dlInsertStudent(lst,student[i]);
    printf("Linked completed !!!\n\n");

    printf("Information about students: \n");
    dlPrint(lst);

    printf("Move to 3rd node completed!!!\n");
    printf("Information\n");
    showData(dlSeek(lst,3)->data);    
    printf("\n");

    lst = dlDelete(lst,dlSeek(lst,3)->prev);
    printf("Delete previous node completed!!!\n\n");

    lst = dlDelete(lst,dlSeek(lst,3-1)->next);
    printf("Delete next node completed!!!\n\n");

    printf("Student information content at the beginning:\n");
    for(i=0;i<5;i++)
        printf("%s %s %d\n",student[i].id,student[i].name,student[i].grade); 
    printf("\n");

    printf("Information about students: \n");
    dlPrint(lst);

    lst = dlDeleteAll(lst);
    printf("Release memory completed!!!\n");

    return 0;
}
