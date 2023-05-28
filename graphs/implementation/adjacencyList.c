#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node{
    int vertex;
    struct Node *next;
};

struct edge{
    int source;
    int destination;
};

struct graph{
    int V;
    int E;
    struct Node *adjList[];      // adjacency list
};

int insertEdge(struct graph *G, struct edge E){

    int n = G->V;    
    int from = E.source;
    int to = E.destination;

    if(0>from || from>n || 0>to || to>n){
        return -1;
    }

    struct Node *prev = NULL;
    struct Node *ptr = G->adjList[from];

    while(ptr != NULL){
        if(ptr->vertex == to){
            return 0;
        }
        else{
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if(ptr == NULL){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = to;
        newNode->next = NULL;
        if(prev == NULL){
            G->adjList[from] = newNode;
        }
        else{
            prev->next = newNode;
        }
    }
    return 1;
}

struct graph* createGraph(const int numVertices){
    assert(numVertices >= 0);
    struct graph *G = (struct graph*)malloc(sizeof(struct graph));

    assert(G != NULL);
    G->V = numVertices;
    G->E = 0;

    //allocating memory for each column and initialise with 0
    for(int i = 0; i< G->V; i++){
        G->adjList[i] = (struct Node*)malloc(sizeof(struct Node));
        G->adjList[i]->vertex = i;
        G->adjList[i]->next = NULL;
    }
    return G;
};

struct edge newEdge(int x, int y){
    struct edge E;
    E.source = x;
    E.destination = y;
    return E;
};

void displayGraph(struct graph *G){
    struct Node *ptr;
    for(int i = 0; i< G->V; i++){
        ptr = G->adjList[i];
        printf("Node %d neighbours: ",i);
        ptr = ptr->next; 
        while(ptr!=NULL){
            printf("%d ",ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main(){
    struct graph *G = createGraph(4);
    struct edge e1 = newEdge(0,1);
    struct edge e2 = newEdge(0,3);
    struct edge e3 = newEdge(1,2);
    struct edge e4 = newEdge(2,0);
    struct edge e5 = newEdge(2,3);
    insertEdge(G,e1);
    insertEdge(G,e2);
    insertEdge(G,e3);
    insertEdge(G,e4);
    insertEdge(G,e5);
    displayGraph(G);
    return 0;
}