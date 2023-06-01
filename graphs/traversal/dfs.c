#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    int *arr;
};

struct stack *createStack(int size){
    struct stack *S =(struct stack*)malloc(sizeof(struct stack));
    S->size = size;
    S->top = -1;
    S->arr = (int*)malloc(S->size*sizeof(int));
    return S;
}

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


// #define V 7

// int adjMat[V][V] = {
//         {0,1,1,1,0,0,0},
//         {1,0,1,0,0,0,0},
//         {1,1,0,1,1,0,0},
//         {1,0,1,0,1,0,0},
//         {0,0,1,1,0,1,1},
//         {0,0,0,0,1,0,0}, 
//         {0,0,0,0,1,0,0} 
//     };
// int visited[V];
 
// void dfs(int i){
//     int j;
//     printf("%d ", i);
//     visited[i] = 1;
//     for(int j =0; j<V; j++){
//         if(adjMat[i][j] == 1 && visited[j] == 0){
//             dfs(j);
//         }
//     }
// }

// int main() {
//     memset(visited, 0, sizeof(visited));
//     dfs(1);
//     return 0;
// }




void dfs(int V, int arr[][V]) {
    struct stack* S = createStack(V);
    int visited[V];
    memset(visited, 0, sizeof(visited));

    int i = 1;
    printf("%d", i);
    visited[i] = 1;
    push(S, i);
    while (!isEmpty(S)) {
        int node = pop(S);
        for (int j = 0; j < V; j++) {
            if (arr[node][j] == 1 && visited[j] == 0) {
                printf(" --> %d", j);
                visited[j] = 1;
                push(S, j);
            }
        }
    }
}

#define V 7
int main() {
    int adjMat[V][V] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    dfs(V, adjMat);
    return 0;
}