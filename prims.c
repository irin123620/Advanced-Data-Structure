#include <stdio.h>
#include <limits.h>  // For INT_MAX

#define MAX 10  // Maximum number of vertices

int n;
int graph[MAX][MAX];

int minKey(int key[], int mstSet[])
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST()
{
    int parent[MAX]; // Array to store MST
    int key[MAX];    // Key values used to pick minimum weight edge
    int mstSet[MAX]; // To represent vertices included in MST

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from first vertex
    key[0] = 0;    
    parent[0] = -1; // First node is root of MST

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet); // Pick minimum key vertex
        mstSet[u] = 1;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (weight, 0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("\nMinimum Spanning Tree using Prim's Algorithm:\n");
    primMST();

    return 0;
}
