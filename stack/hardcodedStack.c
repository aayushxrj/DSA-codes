#include<stdio.h>

// int stack[100];
// int top = -1;
// int size = 100;
createStack(100);
int *createStack(int size){
    int stack[size];
    int top = -1;
    return stack;
}

void push(int val){
    if(top == size-1){
        printf("Overflow");
    }
    else{
        top++;
        stack[top] = val;
    }
}

int peek(){
    if(top == -1){
        printf("Empty stack");
    }    
    else{
        return stack[top];
    }
}



int main(){
    return 0;
}