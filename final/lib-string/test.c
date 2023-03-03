#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//=========Select lib=======
// #include "bst.h"
// #include "llist.h"
#include "hash.h"


//cap phat bo nho dong
data_t* arr ;

//Khai bao hash table
element_t* ht[TABLE_SIZE];//--------> HASH TABLE !

int main(){

    //Open file
    char nameOfFile[] = "test.txt";
    FILE* f = fopen(nameOfFile,"r");
    if(f==NULL){
        printf("ERROR: can't open file !\n");
        return 1;
    }




    /*============================ TEST DYNAMICALLY ==========================*/

    // printf("Test dynamically allocate memory:\n");
    // //Cap phat bo nho dong
    // arr = (data_t*)malloc(1000*sizeof(data_t));
    // if(arr==NULL){ 
    //     printf("ERORR: can't dynamically allocate memory!!!");
    //     return 1;
    // }
    // int n = 0;
    // while (!feof(f))
    // {
    //     fscanf(f,"%s %d", arr[n].key, &arr[n].type);
    //     n++;
    // }
    // for(int i = 0; i < n ; i ++ ) printf("%s&%d\n",arr[i].key,arr[i].type);
    // free(arr);

         /*them 10 phan tu ( neu can ) !*/
        // arr = (data_t*)realloc(arr, 10* sizeof(data_t));
    
    /*=====================================================================*/







    /*============================ TEST LINK LIST ==========================*/

    // printf("Test link list:\n");
    // root_t list = llInit();

   
    // while (!feof(f)){
    //     data_t newData;
    //     fscanf(f,"%s %d",newData.key,&newData.type);
    //     list = llInsertTail(list, newData);
    // }
    
    // printf(">>>LIST: \n");
    // list = llPrint(list);

    // list = llDeleteHead(list);
    // list = llDeleteAfter(list, list->next);
    // list = llDeleteTail(list);

    // printf(">>>List sau khi xoa: \n");
    // list = llPrint(list);

    // list = llDeleteAll(list);

    /*================================================================*/








    /*============================ TEST BST ==========================*/

    // printf("Test BST:\n");
    // tree_t tree = treeInit();
    // while (!feof(f)){
    //     data_t newData;
    //     fscanf(f,"%s %d",newData.key,&newData.type);
    //     Insertnode_t(newData, &tree);
    // }
    // printf(">>>>printInorder:\n");
    // printInorder(tree);
    // node_t* node = Search("vinicius",tree);
    // if(node!=NULL) { printf("\n\n\n>>>>Du lieu tim duoc: \n");showDataOfNode(node->data); }

    // printf("\n\n>>>>Sau khi xoa:\n");
    // Deletenode_t("vinicius", &tree);
    // Deletenode_t("valverde", &tree);
    // Deletenode_t("messi", &tree);
    // printInorder(tree);

    // node = findMax(&tree);
    // printf("\n\n>>>Node max:\n"); showDataOfNode(node->data);

    // node = findMin(&tree);
    // printf("\n\n>>>Node min:\n"); showDataOfNode(node->data);

    // freetree(tree);

    /*=====================================================================*/  








    /*============================ TEST HASH TABLE ==========================*/

    // printf("Test HASH:\n");
    // init_table(ht);

    // printf(">>>>Init HASH:\n");
    // while (!feof(f)){
    //     data_t newData;
    //     fscanf(f,"%s %d",newData.key,&newData.type);
    //     element_t e;
    //     e.data = newData;
    //     e.next = NULL;
    //     insertItem(ht, e);
    //     printf("(key, hash(key)) = (%s, %d)\n", newData.key ,hash(newData.key) );
    // }

    // printf("\n\n>>>>HASH:\n");
    // traverse(ht);

    // printf("\n\n>>>>Du lieu tim duoc:\n");
    // element_t *p = findElement(ht, "valverde");
    // if(p!=NULL) htShowData(p->data);

    // printf("\n\n>>>>>>HASH sau khi xoa:\n");
    // removeElement(ht, "valverde");
    // removeElement(ht, "vinicius");
    // removeElement(ht, "musiala");
    // traverse(ht);
    // clear(ht);
    
    /*=======================================================================*/  

fclose(f);

}