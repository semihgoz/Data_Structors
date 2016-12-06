



#include <stdio.h>

#include <stdlib.h>





int *array;

int size = 2;

int top = 0;



int pop() {

    if (top <= size / 4) {

        int * newArray = (int*) malloc(sizeof (int)*size / 2);



        for (int j = 0; j < size; j++) {

            newArray[j] = array[j];



        }

        free(array);

        array = newArray;

        size = size / 2;



    }

    return array[--top];

}



void push(int i) {

    if (top >= size) {

        int * newArray = (int*) malloc(sizeof (int)*size * 2);



        for (int j = 0; j < size; j++) {

            newArray[j] = array[j];



        }

        free(array);

        array = newArray;

        size = size * 2;

    }

    array[top++] = i;

}

void show() {

    for (int i = 0; i < top; i++) {

        printf("%d ", array[i]);

    }

}


int main() {

    array = (int*) malloc(sizeof (int)*2);

    push(10);

    push(20);

    push(40);

    push(50);

    push(60);

    printf("size: %d ", size);

    printf("%d ,", pop());

    printf("size: %d ", size);

    printf("%d ,", pop());

    printf("size: %d ", size);

    printf("%d ,", pop());

    printf("size: %d ", size);



    printf("%d ,", pop());

    printf("size: %d ", size);



    show();





    return 0;

}


