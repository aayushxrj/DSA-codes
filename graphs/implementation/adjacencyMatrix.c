#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct edge{
    int source;
    int destination;
};

struct graph{
    int V;
    int E;
    int **adjMatrix;      // adjacency matrix
};

struct graph* createGraph(const int numVertices) {
    assert(numVertices >= 0);
    struct graph* G = (struct graph*)malloc(sizeof(struct graph));

    assert(G != NULL);
    G->V = numVertices;
    G->E = 0;

    G->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        G->adjMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }

    return G;
}

void insertEdge(struct graph *G, struct edge E){

    //code
    int v,x,y;
    v = G->V;
    x = E.source;
    y = E.destination;
    if(x >= v || y>= v){
        printf("Invalid edge\n");
    }      
    else{
        G->adjMatrix[x][y] = 1;
        G->adjMatrix[y][x] = 1;
        (G->E)++;
    }
}

struct edge newEdge(int x, int y){
    struct edge E;
    E.source = x;
    E.destination = y;
    return E;
};

void displayGraph(struct graph *G){
    //code
    int V = G->V;
    printf("%d Vertices, %d Edges\n", G->V, G->E);
    for(int i =0; i<V; i++){
        for(int j = 0; j<V; j++){
            printf("%d ", G->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int V;
    scanf("%d", &V);
    struct graph *G = createGraph(V);
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            scanf("%d", &G->adjMatrix[i][j]);
        }
    }


    return 0;
}