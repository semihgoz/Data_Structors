

#include <stdio.h>

#include <stdlib.h>



typedef struct n {

    int data;

    struct n* next;

} node;



int pop(node * root) {

    if (root == NULL) {

        printf("already list is empty");

        return -1;

    }

    if(root->next ==NULL){

        int rvalue = root->data;

        free(root);

        return rvalue;

    }

    node* iter = root;

    while (iter->next ->next != NULL) {

        iter = iter->next;

    }

    

    node *temp = iter->next;



    int rvalue = temp->data;

    iter->next = NULL;

    free(temp);



    return rvalue;





}



node* push(node*root, int data) {

    if (root == NULL) {

        root = (node*) malloc(sizeof (node));

        root->next = NULL;

        root->data = data;

        return root;

    }

    node* iter = root;

    while (iter->next != NULL) {

        iter = iter->next;

    }



    node *temp = (node*) malloc(sizeof (node));

    temp->data = data;

    temp->next = NULL;

    iter->next = temp;

    return root;



}



void show(node * root) {



    while (root == NULL) {

        printf("%d ->", root->data);

        root = root->next;

    }

}



int main() {



    node * s = NULL;



    s = push(s, 10);

    s = push(s, 20);

    s = push(s, 30);

    printf("%d -> ", pop(s));

    printf("%d -> ", pop(s));

    printf("%d -> ", pop(s));

    return 0;

}
