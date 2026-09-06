/*
 * ADJACENCY MATRIX
 *
 * An adjacency matrix is a 2D array used to represent a graph.
 * matrix[u][v] = 1 means there is an edge from vertex u to vertex v.
 *
 * For an undirected graph, every edge is stored in both directions:
 * matrix[u][v] = 1
 * matrix[v][u] = 1
 *
 * TIME COMPLEXITY: O(V^2 + E)
 * - Initializing the V x V matrix takes O(V^2).
 * - Adding E edges takes O(E).
 *
 * SPACE COMPLEXITY: O(V^2)
 * - The matrix stores V x V entries.
 */

#include <iostream>
#include <vector>

using namespace std;

// Builds an adjacency matrix for an undirected graph
void createAdjacencyMatrix(vector<vector<int>>& adjacencyMatrix, const vector<vector<int>>& edges) {
    for (const vector<int>& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // Add edge in both directions
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }
}

void printAdjacencyMatrix(const vector<vector<int>>& adjacencyMatrix) {
    cout << "    ";

    // Print column numbers
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        cout << i << " ";
    }

    cout << "\n";

    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        cout << i << " : ";

        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }

        cout << "\n";
    }
}

int main() {
    int n = 7; // Vertices: 0 to 6

    /*
     *        0 -------- 1
     *       / \        / \
     *      /   \      /   \
     *     2     3 --- 4    5
     *      \          /
     *       \        /
     *        \----- 6
     */

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 3},
        {1, 4},
        {1, 5},
        {2, 6},
        {3, 4},
        {4, 6},
        {5, 6}
    };

    // Initialize V x V matrix with 0
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    // Create adjacency matrix
    createAdjacencyMatrix(adjacencyMatrix, edges);

    // Print adjacency matrix
    printAdjacencyMatrix(adjacencyMatrix);

    return 0;
}