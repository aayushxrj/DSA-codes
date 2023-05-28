#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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

void bfs(int V,int arr[V][V]){
    struct queue *q = createQueue(V);

    int i = 0;
    int visited[V];
    memset(visited, 0, sizeof(visited));

    printf("%d", i);
    visited[i] = 1;
    enqueue(q,i); // enqueuing i for exploration
    while(!isEmpty(q)){
        int node = dequeue(q);
        for(int j = 0; j< V; j++){
            if( arr[node][j] == 1 && visited[j] == 0){
                printf(" --> %d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}


#define V 7
int main() {
    int adjMat[V][V] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    bfs(V, adjMat);

    return 0;
}

