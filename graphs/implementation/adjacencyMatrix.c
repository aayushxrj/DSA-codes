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

void insertEdge(struct graph *G, struct edge E){

    //code 

}

struct graph* createGraph(const int numVertices){
    assert(numVertices >= 0);
    struct graph *G = (struct graph*)malloc(sizeof(struct graph));

    assert(G != NULL);
    G->V = numVertices;
    G->E = 0;

    //code 

    return G;
};

struct edge newEdge(int x, int y){
    struct edge E;
    E.source = x;
    E.destination = y;
    return E;
};

void displayGraph(struct graph *G){
    //code
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