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

    int selected[V];
    memset(selected, false, sizeof(selected));

    no_edge = 0;

    selected[0] = true;

    int x;
    int y;
    printf("Edge : Weight\n");

    while (no_edge < V - 1)
    {

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
                    {
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