#include <stdio.h>
#include <stdlib.h>

void topologicalSortDFSUtil(int v, int visited[], int stack[], int *top, int n, int a[20][20]) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[v][i] == 1 && !visited[i]) {
            topologicalSortDFSUtil(i, visited, stack, top, n, a);
        }
    }
    stack[++(*top)] = v;
}

void topologicalSortDFS(int n, int a[20][20]) {
    int visited[20], stack[20], top = -1;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topologicalSortDFSUtil(i, visited, stack, &top, n, a);
        }
    }

    printf("Topological Sort (DFS): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
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

    topologicalSortDFS(n, a);

    return 0;
}
