#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue(){
    struct Queue *Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->front = Q->rear = NULL;
    printf("Queue created!\n");
    return Q;
}

int isEmpty(struct Queue *Q){
    if(Q->front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Queue *Q, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(!temp){
        printf("Queue full.\n");
    }
    else{
        temp->data = data;
        temp->next = NULL;
        if(isEmpty(Q)){
            Q->front = Q->rear = temp;
        }
        else{
            Q->rear->next = temp;
            Q->rear = temp;
        }
    }
}

int dequeue(struct Queue *Q){
    if(isEmpty(Q)){
        printf("Queue is empty");
    }
    else{
        struct Node *temp = Q->front;
        int data = temp->data;
        Q->front = Q->front->next;
        free(temp);
        temp = NULL;
        return data;
    }
}

int size(struct Queue *Q){
    if(isEmpty(Q)){
        return 0;
    }
    int count = 0;
    struct Node *temp = Q->front;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

void display(struct Queue *Q){
    struct Node *temp = Q->front;
    printf("Stack from front : ");
    while(temp){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    return 0;
}