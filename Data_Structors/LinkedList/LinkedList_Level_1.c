#include <stdio.h>

#include <stdlib.h>



typedef struct n {

    int x;

    struct n* next;

} node;



int main() {



    node * root;

    root=(node*)malloc(sizeof(node)); // create node in memory

    root -> x =10;                    // added to data in node  

    root->next=(node*)malloc(sizeof(node));

    root->next->x=20;

    root->next->next=(node*)malloc(sizeof(node));

    root->next->next->x=30;

    

    node * iter;

    iter=root;

    printf("%d ",iter->x);

    iter=iter->next;

    printf("%d " ,iter->x);



    return 0;

}
