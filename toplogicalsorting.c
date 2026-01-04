#include <stdio.h>

#define MAX 10

int n;
int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int v)
{
    stack[++top] = v;
}

void DFS(int v)
{
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }

    push(v);   // store vertex after visiting all neighbors
}

void topologicalSort()
{
    for(int i = 0; i < n; i++)
        if(visited[i] == 0)
            DFS(i);

    printf("\nTopological Order: ");
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    topologicalSort();

    return 0;
}
