#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define V 9

struct edge {
    int source;
    int destination;
};

struct graph {
    int V;
    int E;
    int **adjMatrix; // adjacency matrix
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

int minDistance(int dist[], bool visited[], int V) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int V) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void Dijkstra(struct graph* G, int src) {
    int V = G->V;
    int dist[V];     // The output array. dist[i] will hold the shortest
                      // distance from src to i
    bool visited[V]; // visited[i] will be true if vertex i is
                     // included in shortest path tree or shortest
                     // distance from src to i is finalized

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, visited, V);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not visited,
            // there is an edge from u to v, and the total
            // weight of path from src to v through u is
            // smaller than the current value of dist[v]
            if (!visited[v] && G->adjMatrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + G->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + G->adjMatrix[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    // int numVertices = 9;
    struct graph* G = createGraph(V);

    // Example graph
    int adjMatrix[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            G->adjMatrix[i][j] = adjMatrix[i][j];
        }
    }

    int start = 0;
    Dijkstra(G, start);

    return 0;
}
