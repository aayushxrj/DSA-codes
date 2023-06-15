#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct stack{
    struct Node *top;
};

struct stack *createStack(){
    struct stack *stk = (struct stack*)malloc(sizeof(struct stack));
    stk->top = NULL;
    printf("Stack created!\n");
    return stk;
}

int isEmpty(struct stack *S){
    if(S->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *S, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(!temp){
        printf("Stack overflow.\n");
    }
    else{
        temp->data =  data;
        temp->next = S->top;
        S->top = temp;
    }
}

int pop(struct stack *S){
    if(isEmpty(S)){
        printf("Stack underflow.\n");
        return -1;
    }
    else{
        struct Node *temp = S->top;
        int data = temp->data;
        S->top = S->top->next;
        free(temp);
        temp = NULL;
        return data;
    }
}

int peek(struct stack *S){
    if(isEmpty(S)){
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        return S->top->data;
    }
}

int size(struct stack *S){
    int count = 0;
    struct Node *temp = S->top;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void display(struct stack *S){
    if(isEmpty(S)){
        printf("Stack is empty.\n");
    }
    else{
        struct Node *temp = S->top;
        while(temp){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct stack *stk = createStack();
    return 0;
}
