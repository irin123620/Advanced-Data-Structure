#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    struct Edge edges[MAX];
    int n, e, i, j;
    int count = 0, minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    // Sort edges by weight
    for (i = 0; i < e - 1; i++)
        for (j = 0; j < e - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (unionSet(u, v)) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            minCost += edges[i].w;
            count++;
        }
    }

    printf("Minimum Cost = %d\n", minCost);

    return 0;
}
