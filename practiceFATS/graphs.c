#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct edge{
    int source;
    int destination;
};
struct graph{
    int V;
    int E;
    int **adjmatrix;
};

struct graph* createGraph(int V){
    struct graph *G = (struct graph *)malloc(sizeof(struct graph));
    G->V = V;
    G->E = 0;

    G->adjmatrix = (int**)malloc(V*sizeof(int *));
    for(int i =0; i<V;i++){
        G->adjmatrix[i] = (int*)calloc(V,sizeof(int));
    }
    return G;
}

void insertEdge(struct graph *G, int x, int y, int weight){
    int V = G->V;
    struct edge e;
    e.destination =x;
    e.source = y;
    G->adjmatrix[x][y] = weight;
    G->adjmatrix[y][x] = weight;
    G->E++;
}


void displayGraph(struct graph *G){
    int V = G->V;
    for(int i =0; i< V; i++){
        for(int j =0; j<V; j++){
            printf("%d", G->adjmatrix[i][j]);
        }
    }
}

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

struct queue *createQueue(int size) {
    struct queue *Q = (struct queue*)malloc(sizeof(struct queue));
    Q->size = size;
    Q->f = Q->r = -1;
    Q->arr = (int*)malloc(Q->size*sizeof(int));
    return Q;
}

int isFull(struct queue *ptr) {
    if (ptr->r == ptr->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct queue *ptr) {
    if (ptr->f == -1 ) { // Check if f is -1 or greater than r
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct queue *ptr, int val) {
    if (isFull(ptr)) {
        printf("Queue Overflow.\n");
    } else {
        ptr->r++;
        ptr->arr[ptr->r] = val;
        if (ptr->f == -1) {
            ptr->f = 0;
        }
    }
}

int dequeue(struct queue *ptr) {
    if (isEmpty(ptr)) {
        printf("No element to dequeue.\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->f];
        ptr->f++;
        if (ptr->f > ptr->r) { // Check if f is greater than r
            ptr->f = ptr->r = -1; // Reset front and rear pointers to -1
        }
        return val;
    }
}

void bfs(struct graph *G, int start){
    int V = G->V;
    struct queue *Q = createQueue(V);
    int visited[V];
    memset(visited,0,sizeof(visited));
    visited[start] = 1;
    printf("%d ", start);
    enqueue(Q,start);

    while(!isEmpty(Q)){
        int node = dequeue(Q);
        for(int j = 0; j<V; j++){
            if(G->adjmatrix[node][j] == 1 && visited[j] ==0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(Q,j);
            }
        }
    }
}

void primsAlgo(struct graph *G, int start){
    int V = G->V;
    int no_edge = 0;
    int visited[V];
    memset(visited,0,sizeof(visited));
    
    visited[start] = 1;

    while(no_edge < V-1){
        int min = 99999;
        int x = 0,y = 0;
        for(int i =0; i<V; i++){
            if(visited[i]){
                for(int j =0; j<V; j++){
                    if(G->adjmatrix[i][j] && visited[j] == 0){
                        if(min > G->adjmatrix[i][j]){
                            min = G->adjmatrix[i][j];
                            x = i;
                            y= j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n",x,y,G->adjmatrix[x][y]);
        visited[y] = 1;
        no_edge++;
    }
}



void dfs(struct graph *G,int *visited,int start){
    int V = G->V;

    printf("%d ", start);    
    visited[start] = 1;

    for(int j = 0; j< V; j++){
        if(G->adjmatrix[start][j] == 1 && visited[j] ==0){
            dfs(G,visited,j);
        }
    }
}

int minDistance(){}
void printSolution(){}
void Dijkstra(){}

int adjMat[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0}, 
    {0,0,0,0,1,0,0} 
};
// int adjMat[5][5] = {{0, 9, 75, 0, 0},
//     {9, 0, 95, 19, 42},
//     {75, 95, 0, 51, 66},
//     {0, 19, 51, 0, 31},
//     {0, 42, 66, 31, 0}};

int main(){
    int V;
    scanf("%d", &V);
    struct graph *G = createGraph(V);

    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            // scanf("%d", &G->adjMatrix[i][j]);
            G->adjmatrix[i][j] = adjMat[i][j];
        }
    }
    // bfs(G,4);
    int visited[V];
    memset(visited,0,sizeof(visited));
    dfs(G,visited,4);
    // primsAlgo(G,0);
    return 0;
}