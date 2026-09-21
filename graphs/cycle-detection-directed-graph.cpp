// Cycle Detection in Directed Graph
//
// Two approaches:
// 1. DFS
// 2. BFS (Kahn's Algorithm)
//
// Key idea:
//
// DFS:
// If we find a node that is already in the CURRENT DFS path, then we have found a cycle.
//
// BFS:
// Remove nodes with indegree 0. If all nodes cannot be processed, a cycle exists.
//
// Time:  O(V + E)
// Space: O(V + E) including adjacency list

#include <vector>
#include <queue>
using namespace std;

// ==================== DFS ====================

bool dfs(
    const vector<vector<int>>& graph,
    vector<bool>& visited,
    vector<bool>& inPath,
    int cur
) {
    visited[cur] = true;
    inPath[cur] = true;

    for (int neighbor : graph[cur]) {

        // Neighbor is already in current DFS path -> cycle
        if (inPath[neighbor])
            return true;

        if (!visited[neighbor])
            if (dfs(graph, visited, inPath, neighbor))
                return true;
    }

    // Remove from current DFS path
    inPath[cur] = false;

    return false;
}


bool hasCycleDFS(const vector<vector<int>>& graph) {
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<bool> inPath(n, false);

    // Directed graph may be disconnected
    for (int i = 0; i < n; i++) 
        if (!visited[i]) 
            if (dfs(graph, visited, inPath, i))
                return true;

    return false;
}


// ==================== BFS ====================
//
// Kahn's Algorithm:
//
// 1. Calculate indegree of every node.
// 2. Add all nodes with indegree 0 to queue.
// 3. Remove them and reduce neighbors' indegree.
// 4. If all V nodes are processed -> no cycle.
// 5. Otherwise -> cycle exists.


bool hasCycleBFS(const vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++)
        for (int v : graph[u]) 
            indegree[v]++;

    queue<int> q;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    int processed = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        processed++;

        for (int neighbor : graph[cur]) {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Not all nodes can be processed -> cycle exists
    return processed != n;
}


// ==================== SUMMARY ====================
//
// DFS:
//
// visited[node]
//      +
// inPath[node]
//      ↓
// inPath[neighbor] == true
//      ↓
//    CYCLE
//
//
// BFS (Kahn's Algorithm):
//
// indegree == 0
//      ↓
// process node
//      ↓
// reduce neighbors' indegree
//      ↓
// processed == V  -> No cycle
// processed < V   -> Cycle
//
//
// Important:
//
// Undirected:
//     visited[neighbor] && neighbor != parent
//
// Directed:
//     neighbor is already in CURRENT DFS PATH
//     OR
//     Kahn's Algorithm cannot process all V nodes
//
// Time:  O(V + E)
// Space: O(V + E) including adjacency list