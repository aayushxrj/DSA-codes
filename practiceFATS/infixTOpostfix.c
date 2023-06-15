#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void push(struct stack *S, char data){
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

int priority(char symbol){
    if(symbol == '/'){
        return 4;
    }
    else if(symbol == '*'){
        return 3;
    }
    else if(symbol == '+'){
        return 2;
    }
    else if(symbol == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

char *InToPost(struct stack *S, char *exp){
    char *postfix = (char*)malloc(strlen(exp)*sizeof(char));
    int j = 0;
    for(int i =0; exp[i]!='\0'; i++){
        if(exp[i]!= '/' && exp[i] != '*'&& exp[i] != '+' && exp[i] != '-'){
            postfix[j] = exp[i];
            j++;
        }
        else{
            if(isEmpty(S)){
                push(S,exp[i]);
            }
            else{
                if(priority(S->arr[S->top]) > priority(exp[i])){
                    postfix[j] = pop(S);
                    j++;
                    push(S,exp[i]);
                }
                else{
                    push(S,exp[i]);
                }
            }
        }
    }
    while (!isEmpty(S)) {
        postfix[j] = pop(S);
        j++;
    }

    postfix[j] = '\0';
    return postfix;
}



int main(){
    struct stack *S = createStack(10);
    char exp[] = "A*B+C";
    printf("Infix Expression : %s\n", exp);
    printf("Postfix Expression : %s",InToPost(S,exp));

    return 0;
}