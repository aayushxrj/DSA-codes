#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
    struct Node *top;
};

struct Stack *createStack(){
    struct Stack *stk = (struct Stack*)malloc(sizeof(struct Stack));
    stk->top = NULL;
    return stk;
};

int isEmpty(struct Stack *stk){
    if(stk->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//error
int isFull(struct Node *stk){
    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    if(n == NULL){
        return 1;
    }
    else{
        free(n);
        return 0;
    }
}

void push(struct Stack *stk, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(isFull(stk)){
        printf("Stack oveflow\n");
        return -1;
    }
    else{
        temp->data = data;
        temp->next = stk->top;
        stk->top = temp;
    }
}

int pop(struct Stack *stk){
    if(isEmpty(stk)){
        printf("Stack undeflow\n");
        return -1;
    }
    else{
        struct Node *temp = stk->top;
        int data = temp->data;
        stk->top = stk->top->next;
        free(temp);
        return data;
    }
}

int peek(struct Stack *stk){
    if(isEmpty(stk)){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return stk->top->data;
    }
}

int size(){}

void display(){}

int main(){
    // STACK named stk is created
    struct Stack *stk = createStack();

    return 0;
}