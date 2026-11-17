/*
 * CONCEPT: BREADTH-FIRST SEARCH (BFS) PATHFINDING
 * Breadth-First Search (BFS) is an iterative traversal algorithm that explores a graph
 * level-by-level using a Queue (FIFO). It visits all immediate neighbors of a node 
 * before moving deeper into the graph, guaranteeing the shortest path in unweighted graphs.
 *
 * TIME COMPLEXITY: O(V + E)
 * - V is the number of vertices, E is the number of edges.
 * - In the worst case, every vertex is pushed and popped from the queue once, 
 *   and every edge is checked once.
 *
 * SPACE COMPLEXITY: O(V)
 * - Visited set (unordered_set) requires O(V) space.
 * - Queue (std::queue) can hold up to O(V) nodes in the worst-case scenario.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// BFS to check if a valid path exists from source to destination
bool bfs(const vector<vector<int>>& adjacencyList, int source, int destination) {
    if (source == destination)
        return true;

    unordered_set<int> vis;
    queue<int> q;

    // Initialize BFS with the source vertex
    vis.insert(source);
    q.push(source);

    while (!q.empty()) {
        int curVertex = q.front();
        q.pop();

        for (int neighbour : adjacencyList[curVertex]) {
            // Early exit if destination is found
            if (neighbour == destination)
                return true;

            // Push unvisited neighbors into the queue
            if (!vis.contains(neighbour)) { // C++20 -> .contains()
                vis.insert(neighbour);
                q.push(neighbour);
            }
        }
    }

    // Queue exhausted and destination not reached
    return false;
}

// Dedicated helper to print the search outcome
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
    
    bool pathExists = bfs(adjacencyList, source, destination);
    printPathResult(source, destination, pathExists);
    
    return 0;
}