#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f,r;
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
    if (ptr->f == -1 ) { // Check if f is -1 or greater than r
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

int main(){
    return 0;
}