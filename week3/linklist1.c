/*
Author: Phung Tien Dat - 20210163
Finish day: 11/14/2022
The program uses the link list to manage student information 
and run tests on the given topic requirements, specifically:
    •Tạo một mảng 5 sinh viên với dữ liệu cho trước: 
        data_t student[] = { {"001", "sv1", 3}, {"002", "sv2", 5}, .... };
    Ttạo một danh sách liên kết từ mảng dữ liệu này bằng cách gọi hàm tương ứng vừa viết ở trên.
    •Hiển thị nội dung danh sách liên kết chứa thông tin các sinh viên 
    •Tìm và hiển thị thông tin của bản ghi của sinh viên có id = "002"
    •Thay đổi điểm của sinh viên có id = "002" thành 9
    •Hiển thị lại nội dung của danh sách sinh viên
    •Xóa sinh viên có id = "001" trong danh sách liên kết ứng
    •Hiển thị nội dung danh sách liên kết chứa thông tin các sinh viên
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct {
    char id[11];
    char name[101];
    int grade;
} data_t;

typedef struct node_s {
    data_t data;
    struct node_s *next;
} node_t, *root_t;


/*init*/
root_t llInit() { return NULL; }

/*show Data*/
void showData(data_t data) { 
    printf("%s %s %d\n", data.id,data.name,data.grade); 
}

/*Print out nodes*/
root_t llPrint(root_t root) {
    for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
    printf("\n");
    return root;
}


/*-----------------------------Insert------------------------------------*/

/*Create new node*/
node_t* createNewNode(const data_t data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*Insert node in the header*/
root_t llInsertHead(root_t root, node_t* pNewNode) {
    pNewNode->next = root;
    return (root_t)pNewNode;
}

/*Insert node in the tail*/
root_t llInsertTail(root_t root,node_t* pNewNode) {
    if (root == NULL) return (root_t)pNewNode;
    node_t* p = NULL;
    for (p = root; p->next != NULL; p = p->next);
    p->next = pNewNode;
    return root;
}

/*Insert node after another node*/
root_t llInsertAfter(root_t root, node_t* pAElem, node_t* pNewNode) {
    if (pAElem == NULL) return root;
    pNewNode->next = pAElem->next;
    pAElem->next = pNewNode;
    return root;
}

/*
!!!Requirement function!!!
Insert a new Student with: 
    root is the pointer to the first node of the list
    data is information of student 
*/
root_t llInsertStudent(root_t root, data_t data){
    node_t* pNewNode = createNewNode(data);
    node_t* prev;
    if(root==NULL){
        root = llInsertHead(root,pNewNode);
        return root;
    }
    node_t* p ;
    for (p = root; p != NULL; p = p->next){
        if(data.grade > p->data.grade && p==root){
            root = llInsertHead(root,pNewNode);
            return root;
        }
    else
        if(data.grade > p->data.grade){
            root = llInsertAfter(root,prev,pNewNode);
            return root;
        }
    else
        if(p->next==NULL){
            root = llInsertTail(root,pNewNode);
            return root;
        }
    prev=p;
    } 
    return root;
}


/*---------------------------find-----------------------------*/

/*!!!Requirement function!!!
Find a Student by number with: 
    root is the pointer to the first node of the list
    id is number student 
*/
data_t* llFindStudent(root_t root, char id[]){

    node_t* p;

    for (p = root; p!=NULL; p = p->next) if(strcmp(id,p->data.id)==0){
        return &p->data;
    }
    return NULL ;
}
/*---------------------------Delete--------------------------*/

/*Delete node in the header*/
root_t llDeleteHead(root_t root) {
    if (root == NULL) return NULL;

    node_t* p = root->next;
    free(root);
    return (root_t)p;
}

/*Delete node in the tail*/
root_t llDeleteTail(root_t root) {
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

/*Delete node after another node*/
root_t llDeleteAfter(root_t root, node_t* pA) {
    if ((pA == NULL) || (pA->next == NULL)) return root;

    node_t* pToDelElem = pA->next;
    pA->next = pA->next->next;

    free(pToDelElem);
    return root;
}

/*
!!!Requirement function!!!
Delete a Student by number with: 
    root is the pointer to the first node of the list
    id is number student
*/
root_t llDeleteStudent(root_t root, char id[]){
    node_t* prev=root;
    if(root==NULL) return root;
    node_t* p ;
    for (p = root; p != NULL; p = p->next) 
    {
        if(strcmp(id,p->data.id)==0){
            if(p==root){
                root = llDeleteHead(root);
                return root;
            }   
        else
            if(p->next==NULL){
                root = llDeleteTail(root);
                return root;
            }
        else
            {
                root = llDeleteAfter(root,prev);
                return root;
            }
    
        } 
        prev=p;
    }
    return root;
}
/*-----------------------Change grade------------------------*/
/*
!!!Requirement function!!!
Change student's score by number with: 
    root is the pointer to the first node of the list
    data is information of student 
    newGrade is the grade that want to change to
*/
root_t llChangeGrade (root_t root, char id[], int newGrade){
    node_t* p ;
    for (p = root; p != NULL; p = p->next) if(strcmp(id,p->data.id)==0){
        p->data.grade = newGrade;
        data_t newData = p->data;
        root = llDeleteStudent(root,id);
        root = llInsertStudent(root,newData);
        return root;
    }
    return root;
}

/*release memory*/
root_t llDeleteAll(root_t root) {
    node_t* p = NULL;
    for (; root != NULL; root = p) {
    p = root->next;
    free(root);
    }
    return NULL;
}


int main(){

    root_t lst = llInit();

    data_t student[] = { {"001", "sv1", 3}, {"002", "sv2", 5}, {"003","sv3",6},{"004","sv4",8},{"005","sv5",10} };
    
    int i;
    for(i=0;i<5;i++)
    {
        lst = llInsertStudent(lst,student[i]);
    }
    printf("Link completed !!!\n\n");
 
    llPrint(lst);
    
    printf("Student information with number 002:\n");
    char ID1[]="002";
    data_t* t = llFindStudent(lst,ID1);
    if(t==NULL){
        printf("Not found !\n");
    }
    else
    {
        printf("%s %s %d\n\n",t->id,t->name,t->grade);
    }

    printf("Change the score of the student with id = \"002\" to 9\n");
    char ID2[]="002";
    int newGrade=9;
    lst = llChangeGrade(lst,ID2,newGrade);
    printf("Completed\n\n");
         
    llPrint(lst);

    printf("Delete the student with id=\"001\" in the linked list\n");
    char ID3[]="001";
    lst = llDeleteStudent(lst,ID3);
    printf("Completed\n\n");
    
    llPrint(lst);

    lst=llDeleteAll(lst);
    return 0;
 
}
