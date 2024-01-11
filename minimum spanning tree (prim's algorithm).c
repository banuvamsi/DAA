#include <stdio.h>
#include <limits.h>

#define V 7

int minKey(int key[], int mstSet[]);

void printMST(int parent[], int n);

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }

    return min_index;
}
int graph[V][V] = {{0, 28, 999, 999, 999, 10, 999},
                         {28, 0, 16, 999, 999, 999, 14},
                         {999, 16, 0, 12, 999, 999, 999},
                         {999, 999, 12, 0, 22, 999, 18},
                         {999, 999, 999, 22, 0, 25, 24},
						 {10, 999, 999, 999, 25, 0, 999},
						 {999, 14, 999, 18, 24, 999, 0}};
int main() {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && key[v] > graph[u][v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, V);

    return 0;
}
void printMST(int parent[], int n) {
    printf("Edge   Weight\n");
	int sum=0;
    for (int i = 1; i < n; i++)
        printf("%d - %d   %d \n", parent[i], i, graph[i][parent[i]]);
    for(int i=1;i<n;i++)
    	sum+=graph[i][parent[i]];
    printf("\n The minimum cost of spanning tree is : %d ",sum);
}
