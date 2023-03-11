#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr,char val){
    if(isFull(ptr)){
        printf("Stack overflow.\n");
        printf("Cannot push %c to the stack!\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow.\n");
        return '\0';
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char peek(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty.");
        return '\0';
    }
    else{
        return ptr->arr[ptr->top];
    }
}

struct stack *createStack(int size){
    struct stack *S =(struct stack*)malloc(sizeof(struct stack));
    S->size = size;
    S->top = -1;
    S->arr = (char*)malloc(S->size*sizeof(char));
    return S;
}

char *postfixToEval(char exp[]){
    struct stack *stk = createStack(100);
    for(int i = 0; exp[i]!='\0'; i++){
        //logic
        
    }
}



int main(){
    char exp[] = "123*+5-";
    printf("Postfix Expression : %s\n", exp);
    printf("Infix Expression : %s",postfixToEval(exp));



    return 0;
}