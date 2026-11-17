/*
 * An adjacency list is a memory-efficient way to represent a graph. Instead of a
 * 2D matrix (which wastes space for sparse graphs), it uses an array (or vector) 
 * of lists. The index represents a vertex, and the list at that index holds all 
 * of its directly connected neighbors.
 *
 * TIME COMPLEXITY: O(V + E)
 * - V is the number of vertices, E is the number of edges.
 * - Initializing empty vectors takes O(V) time.
 * - Iterating through the edge array to insert edges takes O(E) time.
 *
 * SPACE COMPLEXITY: O(V + E)
 * - Outer vector holds V elements.
 * - For an undirected graph, each edge is stored twice (2E total across all inner vectors).
 */

#include <iostream>
#include <vector>

using namespace std;

// Builds an adjacency list from a 2D edge array for an undirected graph
void createAdjacencyList(vector<vector<int>>& adjacencyList, const vector<vector<int>>& edges) {
    for (const vector<int>& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        
        // Add edge in both directions for undirected graph
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
}

void printAdjacencyList(const vector<vector<int>>& adjacencyList) {
    for (size_t i = 0; i < adjacencyList.size(); ++i) {
        cout << "Vertex " << i << " connects to: ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 4; // Number of vertices (0 to 3)
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}}; // Bi-directional
    
    vector<vector<int>> adjacencyList(n);
    createAdjacencyList(adjacencyList, edges);
    
    printAdjacencyList(adjacencyList);
    
    return 0;
}