#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND -1

typedef struct {
    char id[20];
    char name[32];
    int grade;
} student_t;

typedef struct node_s {
    student_t data;
    struct node_s *next;
} node_t, *root_t;


root_t llInit();
void showData(student_t data);
root_t llPrint(root_t root);
node_t* createNewNode(const student_t data);
root_t llInsertHead(root_t root, node_t* pNewNode);
root_t llInsertTail(root_t root,node_t* pNewNode);
root_t llInsertAfter(root_t root, node_t* pAElem, node_t* pNewNode);
root_t llInsertStudent(root_t root, student_t data);
root_t llDeleteAll(root_t root);
root_t middle(root_t start, root_t last);
root_t binarySearchByGrade(root_t head, int key);

int main(){

    student_t aSV[] = {{"001", "sv1", 2},
                       {"002", "sv2", 1},
                       {"003", "sv3", 6},
                       {"004", "sv4", 5},
                       {"005", "sv5", 10}};

    root_t lst = llInit();

    printf("Created a student's link list\n\n");
    for(int i = sizeof(aSV) / sizeof(aSV[0]) - 1; i>= 0 ; i-- ) {
        lst = llInsertStudent(lst, aSV[i]);
    }
    
    printf("Data of student:\n");
    lst = llPrint(lst);
    printf("\n");

    printf("Show the data of the student with the required score\n");
    node_t* p = binarySearchByGrade(lst, 6);
    if(p == NULL ) printf("NOT FOUND!!!\n");
    else showData(p->data);
    printf("\n");

    printf("Released memory\n\n");
    lst = llDeleteAll(lst);

    return 0;
}

/*=========================Functions=============================*/
root_t llInit() { return NULL; }

void showData(student_t data) { printf("%s %s %d\n", data.id, data.name,data.grade); }

// Traversing a list and show
root_t llPrint(root_t root) {
  for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
  printf("\n");
  return root;
}

/*Create new node*/
node_t* createNewNode(const student_t data) {
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
Insert a new Student with: 
    root is the pointer to the first node of the list
    data is information of student 
*/
root_t llInsertStudent(root_t root, student_t data){
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

//Delete all nodes
root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

// function to find out middle element
root_t middle(root_t start, root_t last)
{
    if (start == NULL)
        return NULL;
 
    node_t* slow = start;
    node_t* fast = start -> next;
 
    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
 
    return slow;
}

root_t binarySearchByGrade(root_t head, int key)
{
    node_t* start = head;
    node_t* last = NULL;
 
    do
    {
        // Find middle
        node_t* mid = middle(start, last);
 
        // If middle is empty
        if (mid == NULL)
            return NULL;
        if (mid -> data.grade == key)
            return mid;
        else if (mid -> data.grade < key)
            last = mid;
        else
            start = mid -> next;
    } while ( last == NULL || last != start );
 
    // value not present
    return NULL;
}