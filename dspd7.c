#include <stdio.h>
#include <stdlib.h>

#define NODES 9

int adj[NODES+1][4]; 
int adjSize[NODES+1];

void addEdge(int u, int v) {
    adj[u][adjSize[u]++] = v;
    adj[v][adjSize[v]++] = u;
}


void sortAsc(int arr[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(arr[i] > arr[j]) {
                int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            }
}

void sortDesc(int arr[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(arr[i] < arr[j]) {
                int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            }
}

void BFS(int start) {
    int visited[NODES+1] = {0}, queue[NODES], front=0, rear=0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Exploration order: ");
    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        // sort neighbors ascending
        sortAsc(adj[u], adjSize[u]);
        for(int i=0; i<adjSize[u]; i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

void DFS(int start) {
    int visited[NODES+1] = {0}, stack[NODES], top=-1;
    stack[++top] = start;

    printf("DFS Exploration order: ");
    while(top != -1) {
        int u = stack[top--];
        if(!visited[u]) {
            visited[u] = 1;
            printf("%d ", u);
           
            sortDesc(adj[u], adjSize[u]);
            for(int i=0; i<adjSize[u]; i++) {
                int v = adj[u][i];
                if(!visited[v]) {
                    stack[++top] = v;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    
    for(int i=1; i<=NODES; i++)
        adjSize[i] = 0;

    
    
    for(int i=1; i<=NODES; i++) {
       
        if(i % 3 != 0) addEdge(i, i+1);
       
        if(i <= 6) addEdge(i, i+3);
    }

    BFS(1);
    DFS(1);

    return 0;
}

