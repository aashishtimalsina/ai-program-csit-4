#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to perform DFS starting from a given node
void DFS(int node, int visited[], int adjacencyMatrix[][MAX_NODES], int numNodes) {
    visited[node] = 1;
    printf("%d ", node);
    
    // Traverse all neighbors of the current node
    for (int i = 0; i < numNodes; i++) {
        if (adjacencyMatrix[node][i] == 1 && visited[i] == 0) {
            DFS(i, visited, adjacencyMatrix, numNodes);
        }
    }
}

int main() {
    int numNodes, adjacencyMatrix[MAX_NODES][MAX_NODES], visited[MAX_NODES] = {0};
    
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    
    // Read in the adjacency matrix for the graph
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    
    printf("DFS traversal starting from node 0:\n");
    DFS(0, visited, adjacencyMatrix, numNodes);
    
    return 0;
}
