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

//modified peek for giving posn element
// int peek(struct stack *ptr,int posn){
//     if(isEmpty(ptr)){
//         printf("Stack is empty.");
//         return -1;
//     }
//     else if(posn<0 || posn>ptr->top+1){
//         printf("Not a valid position");
//         return -1;
//     }
//     else{
//         return ptr->arr[ptr->top-posn+1];
//     }
// }

//normal peek
int peek(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty.");
        return -1;
    }
    else{
        return ptr->arr[ptr->top];
    }
}

void display(struct stack *ptr){
    for(int i  = 0;i<ptr->top+1;i++){
        printf("%d\n",ptr->arr[i]);
    }
}
 
int main(){
    struct stack *s =(struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    printf("Stack created!\n");

    return 0;
}