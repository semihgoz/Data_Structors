



#include <stdio.h>

#include <stdlib.h>



typedef struct n {

    int x;

    struct n* next;

    struct n* prev;

} node;



void show(node * r) {

    node * iter;

    iter = r;

    while (iter != NULL) {

        printf("%d ", iter->x);

        iter = iter->next;

    }



}



node* add(node* r, int data) {





    if (r == NULL) {

        r = (node*) malloc(sizeof (node));

        r->next = NULL;

        r->prev = NULL;

        r->x = data;

        return r;

    }

    if (r->x > data) {

        node * temp = (node*) malloc(sizeof (node));

        temp->x = data;

        temp->next = r;

        r->prev = temp;

        temp->prev = NULL;

        return r;

    }

    node* iter = r;



    while (iter->next != NULL && iter->next->x < data) {

        iter = iter->next;

    }



    node * temp = (node*) malloc(sizeof (node));

    temp->x = data;

    temp->next = iter->next;

    temp->prev = iter;

    if (temp->next != NULL) {

        temp->next->prev = temp;

    }

    iter->next = temp;



    return r;



}



node * removeNode(node* r, int data) {

    node * iter = r;

    node * temp;

    

    if (iter->x == data) {

        temp = r;

        r = r->next;

        free(temp);

        return r;

    }

    while (iter->next != NULL && iter->next->x != data) {

        iter = iter->next;

    }

    if (iter->next == NULL) {

        printf("nuber not found");

        return r;

    }



    temp = iter->next;

    iter->next = iter->next->next;

    if (iter->next != NULL) {

        iter->next->prev = iter;

    }



    free(temp);

    return r;







}



int main() {



    node * root;

    root = NULL;

    

    root= add(root,20);

    root= add(root,60);

    root= add(root,10);

    root= add(root,50);

    show(root);

    root=removeNode(root,50);

    show(root);









    return 0;

}


