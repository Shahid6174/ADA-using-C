//Lab Program

#include <stdio.h>

#define MAX 10
#define INF 999

int main() {
    int numVertices;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int minCost = 0;

    printf("Enter the number of vertices:\n");
    scanf("%d", &numVertices);

    printf("Enter the graph data (cost matrix):\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;  // Replace 0 with INF for non-connected edges
            }
        }
    }

    visited[1] = 1;
    printf("The edges of the spanning tree are:\n");

    int numEdges = 1;
    while (numEdges < numVertices) {
        int min = INF;
        int u = -1, v = -1;

        // Find the edge with the minimum cost
        for (int i = 1; i <= numVertices; i++) {
            if (visited[i]) {
                for (int j = 1; j <= numVertices; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d Edge (%d,%d) = %d\n", numEdges++, u, v, min);
            minCost += min;
            visited[v] = 1;
            cost[u][v] = cost[v][u] = INF;  // Mark the edge as used
        }
    }

    printf("\nMinimum cost = %d\n", minCost);
    return 0;
}
