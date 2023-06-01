#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue{
    int size;
    int f,r;
    int *arr;
};

struct queue* createQueue(int size){
    struct queue *Q = (struct queue*)malloc(sizeof(struct queue));
    Q->size = size;
    Q->f = Q->r = -1;
    Q->arr = (int*)malloc(sizeof((Q->size)*sizeof(int)));
    return Q;
}

int isEmpty(struct queue *Q){
    if(Q->f == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct queue *Q){
    if( (Q->r +1 )% Q->size == Q->f){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue *Q, int data){
    if(isFull(Q)){
        printf("Queue is full\n");
    }
    else{
        Q->r = (Q->r+1)%Q->size;
        Q->arr[Q->r] = data;
        if(Q->f == -1){
            Q->f = 0;
        }
    }
}

int dequeue(struct queue *Q){
    if(isEmpty(Q)){
        printf("No element to dequeue.\n");
        return -1;
    }
    else{
        int val = Q->arr[Q->f];
        if(Q->f == Q->r){
            Q->f = Q->r = -1;           
        }
        else{
            Q->f = (Q->f+1)%Q->size;
        }        
        return val;
    }
}

#define V 6

int arr[V][V] = {{ 0, 1, 1, 1, 0, 0},
{1 ,0 ,0 ,1 ,1 ,0},
{1 ,0 ,0 ,1 ,0 ,1},
{1 ,1 ,1 ,0 ,1 ,1},
{0 ,1 ,0 ,1 ,0 ,1},
{0 ,0 ,1 ,1 ,1 ,0}};


void BFS(){
    struct queue *Q = createQueue(V);
    int visited[V];
    memset(visited, 0, sizeof(visited));
    
    int i = 0;
    printf("%d", i);
    visited[i] = 1;

    enqueue(Q,i);

    while(!isEmpty(Q)){
        int node = dequeue(Q);
        for(int j = 0; j<V;j++){
            if(arr[node][j] == 1 && visited[j] == 0){
                printf(" --> %d",j);
                visited[j] =1;
                enqueue(Q,j);
            }
        }
    }
}

int main(){
    BFS();
    
    return 0;
}


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

int isEmpty(struct stack *S){
    if(S->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *S){
    if(S->top == S->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *S,int val){
    if(isFull(S)){
        printf("Stack overflow.\n");
        printf("Cannot push %d to the stack!",val);
    }
    else{
        S->top++;
        S->arr[S->top] = val;
    }
}

int pop(struct stack *S){
    if(isEmpty(S)){
        printf("Stack underflow.");
        return -1;
    }
    else{
        int val = S->arr[S->top];
        S->top--;
        return val;
    }
}
#define V 6

int arr[V][V] = {{ 0, 1, 1, 1, 0, 0},
{1 ,0 ,0 ,1 ,1 ,0},
{1 ,0 ,0 ,1 ,0 ,1},
{1 ,1 ,1 ,0 ,1 ,1},
{0 ,1 ,0 ,1 ,0 ,1},
{0 ,0 ,1 ,1 ,1 ,0}};

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

int main(){
    
    dfs();
    return 0;
}

//dfs ayush kumar -1
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->arr[stack->top--];
}

// Depth-first traversal using stacks
void depthFirstTraversal(int matrix[][MAX_SIZE], int size, int startVertex) {
    int visited[MAX_SIZE] = {0}; // Array to keep track of visited vertices
    Stack stack;
    initStack(&stack);
    push(&stack, startVertex);
    visited[startVertex] = 1;

    printf("Depth-First Traversal: ");

    while (!isEmpty(&stack)) {
        int currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        for (int i = size - 1; i >= 0; i--) {
            if (matrix[currentVertex][i] && !visited[i]) {
                push(&stack, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int size, startVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &size);

    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the starting vertex for depth-first traversal: ");
    scanf("%d", &startVertex);

    depthFirstTraversal(matrix, size, startVertex);

    return 0;
}


//dfs ayush - kuamr - adj list
// DFS algorithm in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int numVertices;
  int* visited;

  // We need int** to store a two dimensional array.
  // Similary, we need struct node** to store an array of Linked lists
  struct node** adjLists;
};

// DFS algo
void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  DFS(graph, 2);

  return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define INF INT_MAX

#define V 5

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

void primsAlgo(){
    int visited[V];
    memset(visited, 0, sizeof(visited));
    int no_edge = 0;
    visited[0] = 1;

    printf("EDGE : WEIGHT\n");
    while(no_edge < V-1){
        int min = INF;
        int x = 0,y=0;
        for(int i =0 ; i <V; i++){
            if(visited[i]){
                for(int j =0 ;j<V; j++){
                    if(visited[j] == 0 && G[i][j]){
                        //find minimum
                        if(min > G[i][j]){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf(" %d - %d : %d\n",x,y,G[x][y]);
        visited[y] = 1;
        no_edge++;
    }
}

int main(){
    primsAlgo();
    return 0;
}