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

int isEmptyS(Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFullS(Stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(Stack *ptr,int val){
    if(isFullS(ptr)){
        printf("Stack overflow.\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(Stack *ptr){
    if(isEmptyS(ptr)){
        printf("Stack underflow.");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peekS(Stack *ptr){
    if(isEmptyS(ptr)){
        printf("Stack is empty.");
        return -1;
    }
    else{
        return ptr->arr[ptr->top];
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

int isFullQ(Queue *ptr){
    if((ptr->r+1)%ptr->size == ptr->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmptyQ(Queue *ptr){
    if(ptr->f == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(Queue *ptr, int val){
    if(isFullQ(ptr)){
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
    if(isEmptyQ(ptr)){
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

void specialDequeue(Queue *ptr){
    //logic ?? dequeues element from front and adds at back
    if(isEmptyQ(ptr)){
        printf("No element to dequeue.\n");
    }
    else{
        enqueue(ptr,dequeue(ptr));
    }
}

int peekQ(Queue *ptr){
    if(isEmptyQ(ptr)){
        printf("Queue is empty.");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->f];
        return val;
    }
}

int condition(Queue *ptr1, Stack *ptr2){
    if(peekS(ptr2) == 1){
        while(/*queue is empty*/!isEmptyQ(ptr1)){
            if(dequeue(ptr1) == 1){
                return 0;
            }
        }
        return 1;
    }
    else{
        while(/*queue is empty*/!isEmptyQ(ptr1)){
            if(dequeue(ptr1) == 0){
                return 0;
            }
        }
        return 1;
    }
}

int result(int n, int *C, int *P){
    int count = n;
    Queue *customers = createQueue(n);
    Stack *pastas  = createStack(n);
    for(int i =0; i<n; i++){
        enqueue(customers,C[i]);
    }
    for(int i =n-1; i>=0; i--){
        push(pastas,P[i]);
    }

    // error in special case
    while(!isEmptyQ(customers) || !condition(customers,pastas)){
        if(peekQ(customers) == peekS(pastas)){
            dequeue(customers);
            pop(pastas);
            count--;
        }
        else{
            specialDequeue(customers);
        }
    }

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