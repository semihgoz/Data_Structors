



#include <stdio.h>

#include <stdlib.h>



int * array;

int queue=0,head=0,size=2;

int deque(){

    if(queue == head){

        printf("list is empty");

        return -1;

    }

    if(queue-head<= size/4){

        int * newArray = (int*)malloc(sizeof(int)*size/2);

        

        for (int i = 0; i < queue-head; i++) {

            newArray[i]=array[head+i];



        }

        queue-=head;

        head=0;

        free(array);

        size /=2;

        array=newArray;



    }

    return array[head++];

    

}



void clear(){

    if(head ==0){

        return ;

    }

    

    for (int i = 0; i < size; i++) {

        array[i]=array[i+head];     

    }

    queue -= head;

    head=0;

}

void enque(int data){

    if(array==NULL){

        array = (int*)malloc(sizeof(int)*size);

    }

    if(queue>=size){

        size *=2;

        int * newArray = (int*)malloc(sizeof(int)*size);

        

        for (int i = 0; i < size/2; i++) {

            newArray[i]=array[i];



        }

        free(array);

        array=newArray;



    }

    array[queue++]=data;

}



int main() {

    

    

    

    for (int i = 0; i < 20; i++) {

        enque(i*10);



    }

    

    for (int i = 0; i < 10; i++) {

        printf("%d ",deque());



    }

    for (int i = 0; i < 20; i++) {

        enque(i*10);



    }

    for (int i = 0; i < 30; i++) {

        printf("%d ",deque());



    }



    return 0;

}


