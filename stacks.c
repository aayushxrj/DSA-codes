#include<stdio.h>
#define SIZE 5

void push(int num);
int pop(int top);
int peek(top);
void display(int arr[]);

int main(){
    int stack[SIZE]={1,2,3,4,5};
    int top = -1;
    int e;
    printf("Menu Options - \n1.Push\n2.Pop\n3.Peek\n");
    printf("Choice : ");
    int op;
    scanf("%d",&op);

    switch(op){
        case 1:
        push(e);
        break;
        case 2:
        pop(top);
        break;
        case 3:
        peek(top);
        break;
        case 4:
        display(stack);
        break;
        default:
        printf("Please enter a valid option");
        break;
    }
    return 0;
}

// void push(int num){


// }
void display(int arr[]){
    for(int i = 0; i<SIZE; i++){
        printf("%d\t",arr[i]);
    }
}