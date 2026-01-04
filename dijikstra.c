#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int graph[MAX][MAX];

int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index = -1;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int src)
{
    int dist[MAX];
    int visited[MAX];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nVertex \tDistance from Source %d\n", src);
    for(int i = 0; i < n; i++)
        printf("%d \t\t%d\n", i, dist[i]);
}

int main()
{
    int src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}
