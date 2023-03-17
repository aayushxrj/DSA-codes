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

int calc(int val1, int val2, char opr){
    if(opr == '/'){
        return val1/val2;
    }
    else if(opr == '*'){
        return val1*val2;
    }
    else if(opr == '+'){
        return val1+val2;
    }
    else if(opr == '-'){
        return val1-val2;
    }
    else{
        return -1;
    }
}

int postfixToEval(char exp[]){
    struct stack *stk = createStack(100);
    for(int i = 0; exp[i]!='\0'; i++){
        //logic 
        if(exp[i] != '/' && exp[i] != '*' && exp[i] != '+' && exp[i] != '-'){
            push(stk,exp[i]);
        }
        else{
            int val1 = pop(stk)-'0';
            int val2 = pop(stk)-'0';
            int result = calc(val1, val2, exp[i]);
            char res = result+'0';
            push(stk, res); 
        }
    }
    int final = peek(stk)-'0';
    return final; 
}



int main(){
    char exp[] = "25+3*"; //21
    printf("Postfix Expression : %s\n", exp);
    printf("Evaluation : %d",postfixToEval(exp));
    return 0;
}


