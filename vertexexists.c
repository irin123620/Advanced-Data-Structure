#include <stdio.h>

#define MAX 20

int visited[MAX];

// DFS function
void dfs(int graph[MAX][MAX], int n, int start) {
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n, graph[MAX][MAX];
    int start, end;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0/1 values):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("Enter end vertex: ");
    scanf("%d", &end);

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Perform DFS from start vertex
    dfs(graph, n, start);

    // Check if end vertex was visited
    if (visited[end] == 1)
        printf("Path exists between %d and %d\n", start, end);
    else
        printf("No path exists between %d and %d\n", start, end);

    return 0;
}
