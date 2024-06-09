#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];
int cost[MAX][MAX];
int numVertices, minCost = 0;

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int unionSets(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
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

    int numEdges = 1;
    printf("The edges of the spanning tree are:\n");

    while (numEdges < numVertices) {
        int min = INF;
        int a = -1, b = -1, u = -1, v = -1;

        // Find the edge with the minimum cost
        for (int i = 1; i <= numVertices; i++) {
            for (int j = 1; j <= numVertices; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        u = find(a);
        v = find(b);

        if (unionSets(u, v)) {
            printf("\n%d Edge (%d,%d) = %d", numEdges++, a, b, min);
            minCost += min;
        }

        cost[a][b] = cost[b][a] = INF;  // Mark the edge as used
    }

    printf("\nMinimum cost = %d\n", minCost);
    return 0;
}
