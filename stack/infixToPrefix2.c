#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int priority (char val){
    // if (val == '('){
    //     return 5;
    // }
    if(val == '/' ){
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

char *InToPost(char exp[]){
    struct stack *ptr = createStack(100);
    char *postfix = (char*)malloc(strlen(exp)*sizeof(char)); 
    int j = 0;
    for (int i =0; exp[i]!= '\0'; i++) {
        if(exp[i] != '(' && exp[i] != '/' && exp[i] != '*'&& exp[i] != '+' && exp[i] != '-'){
            postfix[j] = exp[i];
            j++;
        }
        else if(exp[i] == '('){
            push(ptr,exp[i]);
        }
        else if(exp[i] == ')'){
            for(int k = ptr->top;ptr->arr[k] != '(';k--){
                postfix[j] = pop(ptr);
                j++;
            }
            pop(ptr); 
        }
        else{
            //logic 
            if(isEmpty(ptr)){
                push(ptr,exp[i]);
            }
            else{
                if(priority(ptr->arr[ptr->top])>priority(exp[i])){
                    postfix[j] = pop(ptr);
                    j++;
                    push(ptr,exp[i]);
                }
                else{
                    push(ptr,exp[i]);
                }
            }
        }                
    }
    for(int k = ptr->top;k>=0;k--){
        postfix[j] = pop(ptr);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

//------------------------------------error is here or in postfix conversion code-----------------------------------------------------//

char *infixToPrefix(char exp[]){
    struct stack *stk = createStack(100);
    char *prefix = (char*)malloc(strlen(exp)*sizeof(char));
    char *rev = (char*)malloc(strlen(exp)*sizeof(char));
    char *postfix = (char*)malloc(strlen(exp)*sizeof(char));
    int j =0;

    //reversing it & changing '(' to ')' and vice versa
    for(int i = 0; exp[i]!='\0'; i++){
        push(stk,exp[i]);        
    }
    for(int i = 0; i<strlen(exp); i++,j++){
        char c = pop(stk);
        if(c == '('){
        rev[j] = ')';
        }
        else if(c == ')'){
            rev[j] = '(';            
        }
        else{
            rev[j] = c; 
        }             
    }
    rev[j] = '\0';
    //now postfix convert
    postfix = InToPost(rev);

    //now rev again
    for(int i = 0; postfix[i]!='\0'; i++){
        push(stk,postfix[i]);        
    }
    j = 0;
    for(int i = 0; i<strlen(postfix); i++,j++){
        prefix[j] = pop(stk);        
    }
    prefix[j] = '\0';   
    return prefix;
}


int main(){
    char exp[] = "(A-B/C)*(A/K-L)";
    printf("Infix Expression : %s\n", exp);
    printf("Prefix Expression : %s",infixToPrefix(exp)); //      *-A/BC-/AKL
    return 0;
}


/*
To convert an infix to postfix expression refer to this article Stack | Set 2 (Infix to Postfix). We use the same to convert Infix to Prefix.
Step 1: Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
Step 2: Obtain the “nearly” postfix expression of the modified expression i.e CB*A+.
Step 3: Reverse the postfix expression. Hence in our example prefix is +A*BC.
Note that for Step 2, we don’t use the postfix algorithm as it is. 
There is a minor change in the algorithm. As per https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/ , 
we have to pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. 
But here, we have to pop all the operators from the stack which are greater in precedence than that of the scanned operator. 
Only in the case of “^” operator, we pop operators from the stack which are greater than or equal to in precedence.
*/