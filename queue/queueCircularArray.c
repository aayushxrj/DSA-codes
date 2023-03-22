#include<stdio.h>
#include<stdlib.h>

typedef struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
} Queue ;

Queue *createQueue(int size){
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->size = size;
    Q->f = Q->r = -1;
    Q->arr = (int*)malloc(Q->size*sizeof(int));
    return Q;
}

int isFull(Queue *ptr){
    if((ptr->r+1)%ptr->size == ptr->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Queue *ptr){
    if(ptr->f > ptr->r){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(Queue *ptr, int val){
    if(isFull(ptr)){
        printf("Queue overflow.\n");
    }
    else{
        ptr->r = (ptr->r+1)%ptr->size;
        ptr->arr[ptr->r] = val;
        if(ptr->f == -1){
            ptr->f = 0;
        }
    }
}

int dequeue(Queue *ptr){
    if(isEmpty(ptr)){
        printf("No element to dequeue.\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->f];
        ptr->f = (ptr->f+1)%ptr->size;
        return val;
    }
}

void display(Queue *ptr){
    for(int i  = ptr->f; i <= ptr->r ; i++){
        printf("%d\t",ptr->arr[i]);
    }
}

int main(){
    Queue *q = createQueue(100);
    printf("Circular Queue created.\n");
    return 0;
}