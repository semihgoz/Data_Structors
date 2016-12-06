

#include <stdio.h>

#include <stdlib.h>



typedef struct s {

    int size;

    int top;

    int * array;

} stack;



stack * accesor(){

    stack *s =(stack*)malloc(sizeof(stack));

    s->array=NULL;

    s->size=2;

    s->top=0;

    

    return s;

}

int pop(stack * s) {

    if (s->top <=0 |s->array == NULL) {





        return -1;

    }

    if (s->top <= s->size / 4) {

        int * newArray = (int*) malloc(sizeof (int)*s->size / 2);

        for (int j = 0; j < s->top; j++) {

            newArray[j] = s->array[j];

        }

        free(s->array);

        s->array = newArray;

        s->size = s->size / 2;

    }



    return s->array[--s->top];

}



void push(stack*s, int data) {

    if (s->array == NULL) {

        s->array = (int*) malloc(sizeof (int)*2);



    }

    if (s->top >= s->size-1) {

        int * newArray = (int*) malloc(sizeof (int)*s->size * 2);

        for (int j = 0; j < s->size; j++) {

            newArray[j] = s->array[j];

        }

        free(s->array);

        s->array = newArray;

        s->size = s->size * 2;

    }

    s->array[s->top++]=data;

}



void show(stack* s) {

    

    for (int i = 0; i < s->top; i++) {

        printf("%d ",s->array[i]);



    }





}



int main() {

    

    stack* s1 = accesor();

    stack* s2 = accesor();

    push(s1,10);

    push(s1,11);

    push(s1,12);

    push(s1,13);

    push(s1,14);

    printf(" %d ",s1->size);

    show(s1);

    pop(s1);

    pop(s1);

    pop(s1);

    pop(s1);

    printf(" %d ",s1->size);

    show(s1);

    return 0;

}


