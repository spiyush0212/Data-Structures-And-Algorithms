// Cycle Detection in Undirected Graph
//
// Two approaches:
// 1. DFS
// 2. BFS
//
// Key idea:
// In an undirected graph, if we find an already visited neighbor that is NOT the parent, then a cycle exists.
//
// Time:  O(V + E)
// Space: O(V + E) including adjacency list


#include <vector>
#include <queue>
using namespace std;


// ==================== DFS ====================

bool hasCycleDFS(
    const vector<vector<int>>& graph,
    vector<bool>& visited,
    int cur,
    int parent
) {
    visited[cur] = true;

    for (int neighbor : graph[cur]) {

        // Already visited and not parent -> cycle
        if (visited[neighbor] && neighbor != parent)
            return true;

        if (!visited[neighbor])
            if (hasCycleDFS(graph, visited, neighbor, cur))
                return true;
    }

    return false;
}


// ==================== BFS ====================

bool hasCycleBFS(
    const vector<vector<int>>& graph,
    vector<bool>& visited
) {
    queue<pair<int, int>> q;

    q.push({0, -1});
    visited[0] = true;

    while (!q.empty()) {
        auto [cur, parent] = q.front();
        q.pop();

        for (int neighbor : graph[cur]) {

            // Already visited and not parent -> cycle
            if (visited[neighbor] && neighbor != parent)
                return true;

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, cur});
            }
        }
    }

    return false;
}


// DFS:
// Recursive call -> goes deep
//
// BFS:
// Queue -> processes level by level
//
// Both:
// visited[neighbor] && neighbor != parent
//              ↓
//          cycle found