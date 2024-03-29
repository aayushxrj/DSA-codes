// #include<stdio.h>
// #include<stdlib.h>

// struct queue{
//     int size;
//     int f;
//     int r;
//     int *arr;
// };

// struct queue *createQueue(int size){
//     struct queue *Q = (struct queue*)malloc(sizeof(struct queue));
//     Q->size = size;
//     Q->f = Q->r = -1;
//     Q->arr = (int*)malloc(Q->size*sizeof(int));
//     return Q;
// }

// int isFull(struct queue *ptr){
//     if(ptr->r == ptr->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// //wrong
// int isEmpty(struct queue *ptr){
//     if(ptr->f == -1 || ptr->f > ptr->r){
//     // if(ptr->f == ptr->r ){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// void enqueue(struct queue *ptr, int val){
//     if(isFull(ptr)){
//         printf("Queue Overflow.\n");
//     }
//     else{
//         ptr->r++;
//         ptr->arr[ptr->r] = val;
//         if(ptr->f == -1){
//             ptr->f = 0;
//         }
//     }
// }
// //wrong
// int dequeue(struct queue *ptr){
//     if(isEmpty(ptr)){
//         printf("No element to dequeue.\n");
//         return -1;
//     }
//     else{
//         int val = ptr->arr[ptr->f];
//         ptr->f++;
//         return val;
//     }
// }

// void display(struct queue *ptr){
//     for(int i  = ptr->f; i <= ptr->r ; i++){
//         printf("%d\t",ptr->arr[i]);
//     }
// }

// int main(){
//     struct queue *q = createQueue(100);
//     printf("Queue created.\n");
//     enqueue(q,10);
//     enqueue(q,10);
//     enqueue(q,10);
//     enqueue(q,10);
//     // display(q);
//     // dequeue(q);
//     // dequeue(q);
//     // dequeue(q);
//     // dequeue(q);
//     // display(q);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

struct queue *createQueue(int size) {
    struct queue *Q = (struct queue*)malloc(sizeof(struct queue));
    Q->size = size;
    Q->f = Q->r = -1;
    Q->arr = (int*)malloc(Q->size*sizeof(int));
    return Q;
}

int isFull(struct queue *ptr) {
    if (ptr->r == ptr->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct queue *ptr) {
    if (ptr->f == -1 || ptr->f > ptr->r) { // Check if f is -1 or greater than r
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct queue *ptr, int val) {
    if (isFull(ptr)) {
        printf("Queue Overflow.\n");
    } else {
        ptr->r++;
        ptr->arr[ptr->r] = val;
        if (ptr->f == -1) {
            ptr->f = 0;
        }
    }
}

int dequeue(struct queue *ptr) {
    if (isEmpty(ptr)) {
        printf("No element to dequeue.\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->f];
        ptr->f++;
        if (ptr->f > ptr->r) { // Check if f is greater than r
            ptr->f = ptr->r = -1; // Reset front and rear pointers to -1
        }
        return val;
    }
}

void display(struct queue *ptr) {
    for (int i = ptr->f; i <= ptr->r; i++) {
        printf("%d\t", ptr->arr[i]);
    }
}

int main() {
    struct queue *q = createQueue(100);
    printf("Queue created.\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}
