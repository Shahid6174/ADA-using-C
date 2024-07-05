//Lab Program

#include <stdio.h>

#define INF 999
#define MAX 10

void dijkstra(int numNodes, int source, int cost[MAX][MAX], int dist[]) {
    int flag[MAX], count, minDist, nextNode;

    // Initialize distances and flags
    for (int i = 1; i <= numNodes; i++) {
        flag[i] = 0;
        dist[i] = cost[source][i];
    }

    flag[source] = 1;
    dist[source] = 0;
    count = 1;

    while (count < numNodes) {
        minDist = INF;

        // Find the node with the minimum distance
        for (int i = 1; i <= numNodes; i++) {
            if (dist[i] < minDist && !flag[i]) {
                minDist = dist[i];
                nextNode = i;
            }
        }

        // Include the nextNode in the shortest path tree
        flag[nextNode] = 1;
        count++;

        // Update distances of the adjacent nodes of the nextNode
        for (int i = 1; i <= numNodes; i++) {
            if (!flag[i] && (minDist + cost[nextNode][i] < dist[i])) {
                dist[i] = minDist + cost[nextNode][i];
            }
        }
    }
}

int main() {
    int numNodes, source;
    int cost[MAX][MAX], dist[MAX];

    printf("Enter number of nodes:\n");
    scanf("%d", &numNodes);

    printf("Enter cost matrix:\n");
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF; // Replace 0 with INF for non-connected nodes
            }
        }
    }

    printf("Enter the source vertex:\n");
    scanf("%d", &source);

    dijkstra(numNodes, source, cost, dist);

    printf("Shortest paths from source vertex %d:\n", source);
    for (int i = 1; i <= numNodes; i++) {
        if (i != source) {
            printf("%d -> %d : %d\n", source, i, dist[i]);
        }
    }

    return 0;
}
