// #include<stdio.h>
// #include<limits.h>
// #include<string.h>
// #include<stdbool.h>

// #define V 5

// int main(){

//     int G[V][V] = { { 0, 2, 0, 6, 0 },
//                     { 2, 0, 3, 8, 5 },
//                     { 0, 3, 0, 0, 7 },
//                     { 6, 8, 0, 0, 9 },
//                     { 0, 5, 7, 9, 0 } };

//     bool visited[V];
//     memset(visited, false, sizeof(visited));
//     int min = INT_MAX;
//     int no_edge = 0;

//     int x = -1, y = -1;

//     visited[0] = true;
//     while(no_edge < V-1){
//         min = INT_MAX;
//         for(int i =0; i<V; i++){
//             if(visited[i]){
//                 for(int j = 0; j<V; j++){
//                     if(!visited[j] && G[i][j]){
//                         if(min > G[i][j]){
//                             min = G[i][j];
//                             x = i; y = j;
//                         }
//                     }
//                 }
//             }
//         }
//         printf("%d - %d : %d\n", x, y, G[x][y]);
//         visited[y] = true;
//         no_edge++;
//     }
//     return 0;
// }

// Prim's Algorithm in C
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

// number of vertices in graph
#define V 5

// create a 2d array of size 5x5
// for adjacency matrix to represent graph
int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    int no_edge; // number of edge

    // create a array to track selected vertex
    // selected will become true otherwise false
    int selected[V];

    // set selected false initially
    memset(selected, false, sizeof(selected));

    // set number of edge to 0
    no_edge = 0;

    // the number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in
    // graph

    // choose 0th vertex and make it true
    selected[0] = true;

    int x; //  row number
    int y; //  col number

    // print for edge and weight
    printf("Edge : Weight\n");

    while (no_edge < V - 1)
    {
        // For every vertex in the set S, find the all adjacent vertices
        //  , calculate the distance from the vertex selected at step 1.
        //  if the vertex is already in the set S, discard it otherwise
        // choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
}