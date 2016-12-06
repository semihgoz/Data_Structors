#include <stdio.h>

#include <stdlib.h>



typedef struct n {

    int x;

    struct n* next;

} node;

int main() {



    node * root;      // root is a node's pointer 

    root=(node*)malloc(sizeof(node)); // create node in memory

    root -> x =10;                    // added to data in node  

   

    root->next=(node*)malloc(sizeof(node)); 

    root->next->x=20;

    root->next->next=(node*)malloc(sizeof(node));

    root->next->next->x=30;

    root->next->next->next=NULL;  // declaring centinalt

    

    node * iter;        // create a iterator

    iter=root;

    printf("%d ",iter->x);

    iter=iter->next;

    printf("%d " ,iter->x);

    

    iter=root;

    

    while (iter != NULL) {

        printf("%d ",iter->x);

        iter=iter->next;

        

    }

    iter=root;

    while (iter->next != NULL) { // This is a loop that shows the end of the list

        iter = iter->next;

    }

    

    int i =0;

    for (i = 0; i < 5; i++) {

        iter->next = (node*)malloc(sizeof(node));

        iter=iter->next;

        iter->x=i*10;

        iter->next=NULL;

        

    }

    

    iter=root;

    

    while (iter->next != NULL) {

        printf("%d ",iter->x);

        iter=iter->next;

    }

    return 0;

}
