



#include <stdio.h>

#include <stdlib.h>



typedef struct n{

    int data;

    struct n next;

}node;



node * root=NULL;

node * last=NULL;

int dequeue(){

    if(root==NULL){

        return -1;

    }

    int rvalue =root->data;

    node * temp =root;

    root=root->next;

    free(temp);

    return rvalue;

    

}

void enqueue(int data){

    if(root==NULL){

        root=(node*)malloc(sizeof(node));

        root->data=data;

        root->next=NULL;

        last=root;

        return ;

    }

    last->next=(node*)malloc(sizeof(node));

    last->next->data=data;

    last=last->next;

    last->next=NULL;

    

}

void clear(){

    

}

int main() {

    

    return 0;

}


