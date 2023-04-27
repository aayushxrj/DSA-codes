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
    printf("Stack created!\n");
    return stk;
}

int isEmpty(struct Stack *stk){
    if(stk->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack *stk, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Stack overflow.\n");
    }
    else{
        temp->data = data;
        temp->next = stk->top;
        stk->top = temp;
    }
}

int pop(struct Stack *stk){
    if(isEmpty(stk)){
        printf("Stack underflow.\n");
        return -1;
    }
    else{
        struct Node *temp = stk->top;
        int data = temp->data;
        stk->top = stk->top->next;
        free(temp);
        temp = NULL;
        return data;
    }
}

int peek(struct Stack *stk){
    if(isEmpty(stk)){
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        return stk->top->data;
    }
}

int size(struct Stack *stk){
    int count = 0;
    if(isEmpty(stk)){
        return 0;
    }
    struct Node *temp = stk->top;
    while(temp){
        temp= temp->next;
        count++;
    }
    return count;
}

void display(struct Stack *stk){
    struct Node *temp = stk->top;
    printf("Stack contents from top: ");
    while(temp){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Stack *stk = createStack();
    push(stk,10);
    push(stk,20);
    push(stk,30);
    push(stk,40);
    display(stk);
    printf("\n");
    printf("%d\n",size(stk));
    printf("\nPopped : %d",pop(stk));
    printf("\nPopped : %d",pop(stk));
    printf("\nPopped : %d",pop(stk));
    printf("\n");
    printf("%d\n",size(stk));
    display(stk);
    return 0;
}