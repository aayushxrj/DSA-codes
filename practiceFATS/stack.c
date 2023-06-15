#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    char *arr;
};

struct stack* createStack(int size){
    struct stack *S  = (struct stack*)malloc(sizeof(struct stack));
    S->size = size;
    S->top = -1;
    S->arr = (char*)malloc(S->size*sizeof(char));
    return S;
} 

int isEmpty(struct stack *S){
    if(S->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *S){
    if(S->top == S->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *S, int data){
    if(isFull(S)){
        printf("Stack is full\n");
    }
    else{
        S->top++;
        S->arr[S->top] = data;
    }
}

char pop(struct stack *S){
    if(isEmpty(S)){
        printf("Stack is empty\n"); 
        return '\0';
    }
    else{
        char data = S->arr[S->top];
        S->top--;
        return data;
    }
}

char peek(struct stack *S){
    if(isEmpty(S)){
        printf("Stack is empty\n");
        return '\0';
    }
    else{
        return S->arr[S->top];
    }
    
}

int main(){
    struct stack *S = createStack(10);
    push(S,'A');
    printf("%c", peek(S));
    printf("%c", pop(S));
    printf("%c", peek(S));

    return 0;
}