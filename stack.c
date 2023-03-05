#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack overflow.\n");
        printf("Cannot push %d to the stack!",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
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

int peek(struct stack *ptr,int posn){
    if(isEmpty(ptr)){
        printf("Stack is empty.");
        return -1;
    }
    else if(posn<0 || posn>ptr->top+1){
        printf("Not a valid position");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-posn+1];
    }
}

void display(struct stack *ptr){
    for(int i  = 0;i<ptr->top+1;i++){
        printf("%d\n",ptr->arr[i]);
    }
}
 
int main(){
    // struct stack s;
    // s->size = 80;
    // s->top = -1;
    // s->arr = (int*)malloc(s->size*sizeof(int));

    struct stack *s =(struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    printf("Stack created!\n");

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);

    // printf("Element popped : %d",pop(s));
    // printf("%d",peek(s,5));
    display(s);



    //pushing element manually
    // s->arr[0] = 7;
    // s->top++;
    //check if stacks is empty
    // if(isEmpty(s)){
    //     printf("The stack is empty.");
    // }
    // else{
    //     printf("The stack is not empty.");
    // }
    return 0;
}