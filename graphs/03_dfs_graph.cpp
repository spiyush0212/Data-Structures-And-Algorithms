/*
 * Depth-First Search (DFS) is a traversal algorithm that explores a graph by going 
 * as deep as possible along each branch before backtracking.
 *
 * TIME COMPLEXITY: O(V + E)
 * - V is the number of vertices, E is the number of edges.
 * - In the worst case, every vertex is visited once and every edge is traversed once.
 *
 * SPACE COMPLEXITY: O(V)
 * - Visited set (unordered_set) requires O(V) space.
 * - Call stack depth can reach O(V) in the worst case (e.g., linked-list style graph).
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Recursive DFS to find if a path exists from curVertex to destination
bool dfs(const vector<vector<int>>& adjacencyList, unordered_set<int>& vis, int curVertex, int destination) {
    // Mark current vertex as visited
    vis.insert(curVertex);

    // Base case: reached destination
    if (curVertex == destination)
        return true;
    
    // Traverse all unvisited neighbors
    for (int neighbour : adjacencyList[curVertex])
        if (!vis.contains(neighbour)) // C++20 -> .contains()
            if (dfs(adjacencyList, vis, neighbour, destination)) 
                return true; 

    return false;
}

void printPathResult(int source, int destination, bool pathExists) {
    if (pathExists) {
        cout << "Valid path exists from " << source << " to " << destination << "!\n";
    } else {
        cout << "No path exists from " << source << " to " << destination << ".\n";
    }
}

int main() {
    // Adjacency list representation: 0 -- 1 -- 2 -- 3
    vector<vector<int>> adjacencyList = {
        {1},       // Neighbors of 0
        {0, 2},    // Neighbors of 1
        {1, 3},    // Neighbors of 2
        {2}        // Neighbors of 3
    };
    
    int source = 0;
    int destination = 3;
    unordered_set<int> visited;
    
    bool pathExists = dfs(adjacencyList, visited, source, destination);
    printPathResult(source, destination, pathExists);
    
    return 0;
}