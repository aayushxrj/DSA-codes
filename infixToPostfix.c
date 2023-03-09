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
        return -1;
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
        return -1;
    }
    else{
        return ptr->arr[ptr->top];
    }
}

int priority (char val){
    if (val == '('){
        return 5;
    }
    else if(val == '/' ){
        return 4;
    }
    else if (val == '*' ){
        return 3;
    }
    else if(val == '+'){
        return 2;
    }    
    else if(val == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

char InToPost(struct stack *ptr, char arr[]){
    for (int i =0; arr[i]!= '\0'; i++) {
        if(arr[i] !='(' || arr[i] != '/' || arr[i] != '*'|| arr[i] != '+' || arr[i] != '-'){
            //logic correct?
            printf("%c",arr[i]);
        }
        else{
            //logic
        }                
    }
}


int main(){
    struct stack *s =(struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*)malloc(s->size*sizeof(char));

    char exp[] ="A*(B+C)";
    InToPost(s,exp);


    return 0;
}