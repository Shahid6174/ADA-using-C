#include <stdio.h>
#include <stdlib.h>

void topologicalSortKahn(int n, int a[20][20]) {
    int in_degree[20] = {0};
    int queue[20], front = 0, rear = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            queue[++rear] = i;
        }
    }

    int count = 0;
    int top_order[20];

    while (front <= rear) {
        int u = queue[front++];
        top_order[count++] = u;

        for (int i = 1; i <= n; i++) {
            if (a[u][i] == 1) {
                if (--in_degree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    if (count != n) {
        printf("There exists a cycle in the graph\n");
        return;
    }

    printf("Topological Sort (Kahn's Algorithm): ");
    for (int i = 0; i < count; i++) {
        printf("%d ", top_order[i]);
    }
    printf("\n");
}

int main() {
    int n, a[20][20];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    topologicalSortKahn(n, a);

    return 0;
}
