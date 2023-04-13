#include<stdio.h>
#include<stdlib.h>

typedef struct stack{                        //Defining the structure of stack and all its operation as functions
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

typedef struct queue{           //Defining the structure of queue and all its operation as functions
    int f;
    int r;
    int size;
    int *arr;
} Queue;

Queue *createQueue(int size) {
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->size = size;
    Q->f = Q->r = -1;
    Q->arr = (int*)malloc(Q->size*sizeof(int));
    return Q;
}

int isFullQ(Queue *ptr) {
    if (ptr->r == ptr->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmptyQ(Queue *ptr) {
    if (ptr->f == -1 || ptr->f > ptr->r) { 
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *ptr, int val) {
    if (isFullQ(ptr)) {
        printf("Queue Overflow.\n");
    } else {
        ptr->r++;
        ptr->arr[ptr->r] = val;
        if (ptr->f == -1) {
            ptr->f = 0;
        }
    }
}

int dequeue(Queue *ptr) {
    if (isEmptyQ(ptr)) {
        printf("No element to dequeue.\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->f];
        ptr->f++;
        if (ptr->f > ptr->r) { 
            ptr->f = ptr->r = -1;
        }
        return val;
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
/*This function peeks the stack and checks 
if same element is present in the queue 
returns False if present else True*/

int condition(Queue *ptr1, Stack *ptr2){     
    if(isEmptyS(ptr2)){                                       
        return 1;                         
    }
    else if(peekS(ptr2) == 1){
        while(!isEmptyQ(ptr1)){           //Dequeuing till the queue is empty
            if(dequeue(ptr1) == 1){
                return 0;
            }
        }
        return 1;
    }
    else{
        while(!isEmptyQ(ptr1)){           //Dequeuing till the queue is empty
            if(dequeue(ptr1) == 0){
                return 0;
            }
        }
        return 1;
    }
}

int result(int n, int *C, int *P){              //Function returns the number of customers that are unable to eat.
    int count = n;
    Queue *customers = createQueue(n);         //Stack & Queue created
    Stack *pastas  = createStack(n);
    for(int i =0; i<n; i++){                   //unpacking the arrays into the stack and queue
        enqueue(customers,C[i]);
    }
    for(int i =n-1; i>=0; i--){
        push(pastas,P[i]);
    }

    while(!isEmptyQ(customers) || !condition(customers,pastas)){ 
        if(peekQ(customers) == peekS(pastas)){          // if both peeks return same value then we dequeue and pop simultaneously
            dequeue(customers);
            pop(pastas);
            count--;
        }
        else{
            enqueue(customers,dequeue(customers));               //dequeuing the customer from front and enqueuing it at back
        }
    }
    return count;
}

int main(){
    int n;                        //taking number of customers as input
    scanf("%d",&n);
    int C[n], P[n];
    for(int i =0; i<n; i++){      //Storing the customers and pastas in arrays
        scanf("%d",&C[i]);
    }
    for(int i =0; i<n; i++){
        scanf("%d",&P[i]);
    }
    printf("%d",result(n,C,P));
    return 0;
}