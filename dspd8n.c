#include <stdio.h>
#define MAX 100

int parent[MAX]; 
int find(int i) {
    if (parent[i] == i)
        return i;
    parent[i] = find(parent[i]);
    return parent[i];
}

void unionSet(int u, int v) {
    int setU = find(u);
    int setV = find(v);
    parent[setU] = setV;
}

typedef struct {
    int u, v, weight;
} Edge;

void swap(Edge* a, Edge* b) {
    Edge temp = *a;
    *a = *b;
    *b = temp;
}


void sortEdges(Edge edges[], int edgeCount) {
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                swap(&edges[j], &edges[j + 1]);
            }
        }
    }
}

int main() {
    int vertexCount, edgeCount;
    Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertexCount);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    printf("Enter each edge as: u v weight\n");
    for (int i = 0; i < edgeCount; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    
    for (int i = 0; i < vertexCount; i++) {
        parent[i] = i;
    }

    
    sortEdges(edges, edgeCount);

    printf("\nEdges in the Minimum Spanning Tree:\n");
    int mstWeight = 0, edgesUsed = 0;

    for (int i = 0; i < edgeCount && edgesUsed < vertexCount - 1; i++) {
        int uSet = find(edges[i].u);
        int vSet = find(edges[i].v);


        if (uSet != vSet) {
            printf("Edge (%d - %d) with weight %d\n", edges[i].u, edges[i].v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSet(uSet, vSet);
            edgesUsed++;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);

    return 0;
}
