#include <stdio.h>
#include <string.h>


//=========Select lib=======
#include "bst.h"
#include "llist.h"
#include "hash.h"


void task1(){

}

void task2(){
    
}

void task3(){
    
}

void task4(){
    
}

void task5(){
    

}

void task6(){
    
}

void task7(){
    
}




int main(){

//=============bst-tmp=================

//=============llist-tmp===============

//=============hash-tmp================

//==============Dynamic================

int option; //----> select option
while (1)
{
    /*Menu*/
    printf("==============================\n");
    printf("1. \n");
    printf("2. \n");
    printf("3. \n");
    printf("4. \n");
    printf("5. \n");
    printf("6. \n");
    printf("7. \n");
    printf("==============================\n");

    printf(">>>>>Enter your option: \n");
    scanf("%d",&option);

    if( option == 1 ){
        task1();
    }
    else if( option == 2 ){
        task2();
    }
    else if( option == 3 ){
        task3();
    }
    else if( option == 4 ){
        task4();
    }
    else if( option == 5 ){
        task5();
    }
    else if( option == 6 ){
        task6();
    }
    else if( option == 7 ){
        task7();
    }
    else{
        return 0;
        // fclose();
        // free();
        // freetree(tree);
        // list = llDeleteAll(list);
        // clear(ht);
    }

}

}