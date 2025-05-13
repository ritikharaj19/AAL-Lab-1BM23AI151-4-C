#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initializeGraph(Graph* g, int vertices) {
    g->vertices = vertices;
int i;
    for (i = 0; i < vertices; i++) {
    	int j;
        for ( j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
}

void dfs(Graph* g, int v, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1;
int i;
    for ( i = 0; i < g->vertices; i++) {
        if (g->adj[v][i] && !visited[i]) {
            dfs(g, i, visited, stack, stackIndex);
        }
    }

    stack[(*stackIndex)++] = v;
}

void topologicalSort(Graph* g) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackIndex = 0;
int i;
    for ( i = 0; i < g->vertices; i++) {
        if (!visited[i]) {
            dfs(g, i, visited, stack, &stackIndex);
        }
    }

    printf("Topological Sort: ");
    for ( i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    Graph g;
    int vertices = 6;

    initializeGraph(&g, vertices);
    addEdge(&g, 5, 2);
    addEdge(&g, 5, 0);
    addEdge(&g, 4, 0);
    addEdge(&g, 4, 1);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 1);

    topologicalSort(&g);

    return 0;
}
