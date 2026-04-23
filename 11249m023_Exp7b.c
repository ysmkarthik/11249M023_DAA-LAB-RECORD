#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b)
{
    return ((int *)a)[2] - ((int *)b)[2];
}

void makeSet(int parent[], int rank[], int V)
{
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[])
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalAlgo(int V, int E, int edge[E][3])
{
    qsort(edge, E, sizeof(edge[0]), comparator);

    int parent[V], rank[V];
    makeSet(parent, rank, V);

    int minCost = 0;

    for (int i = 0; i < E; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSet(u, v, parent, rank);
            minCost += wt;
        }
    }

    return minCost;
}

int main()
{
    int edge[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int V = 4; // vertices: 0,1,2,3
    int E = 5;

    printf("MST cost: %d\n", kruskalAlgo(V, E, edge));
    return 0;
}
