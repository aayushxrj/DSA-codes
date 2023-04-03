#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int size;
    int *arr;
} Stack;

Stack *createStack(int size){
    Stack *S =(Stack*)malloc(sizeof(Stack));
    S->size = size;
    S->top = -1;
    S->arr = (int*)malloc(S->size*sizeof(int));
    return S;
}

int isEmpty(Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(Stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack overflow.\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow.");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


typedef struct circularQueue{
    int f;
    int r;
    int size;
    int *arr;
} Queue;

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
    if(ptr->f == -1){
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
        if(ptr->f == ptr->r){
            ptr->f = ptr->r = -1;           
        }
        else{
            ptr->f = (ptr->f+1)%ptr->size;
        }        
        return val;
    }
}





int result(int n, int *C, int *P){
    int count = 0;
    Queue *customers = createQueue(n);
    Stack *pastas  = createStack(n);
    for(int i =0; i<n; i++){
        enqueue(customers,C[i]);
    }
    for(int i =n-1; i>=0; i++){
        push(pastas,P[i]);
    }

    // now logic??
    


    return count;
}

int main(){
    int n;
    scanf("%d",&n);
    int C[n], P[n];
    for(int i =0; i<n; i++){
        scanf("%d",&C[i]);
    }
    for(int i =0; i<n; i++){
        scanf("%d",&P[i]);
    }
    printf("%d",result(n,C,P));
    return 0;
}