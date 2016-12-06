

#include <stdio.h>

#include <stdlib.h>



typedef struct n {

    int x;

    struct n* next;

} node;

void show(node * r){ 

    node * iter;

    iter =r;

    while (iter!=NULL) {

        printf("%d ",iter->x);

        iter=iter->next;

    }



}



void add(node * r,int x){ //Function that adds data at 

                           // e end of the listen

    node * iter;

    iter=r;

    

    while (iter->next != NULL) {

        iter=iter->next;

    }

    iter->next=(node*)malloc(sizeof(node));

    iter->next->x=x;

    iter->next->next=NULL;

}



int main() {



    node * root;                      // root is a node's pointer 

    root=(node*)malloc(sizeof(node)); // create node in memory

    root -> x =1;                    // added to data in node  

    root->next=NULL;

    int i =0;

    

    for(i = 0 ; i<5; i++){   

        add(root,i*10);

        

    }

    

    show(root);

    

    return (EXIT_SUCCESS);

}

