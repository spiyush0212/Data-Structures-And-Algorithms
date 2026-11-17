#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
==================================================
TOPOLOGICAL SORT
==================================================

Works on a DIRECTED graph.

For every edge u -> v:
u must come before v.

Valid only if graph is a DAG (no cycle).

Time:  O(V + E)
Space: O(V)
==================================================
*/


/*
==================================================
DFS:
    Cycle -> state == 1
    Order -> Postorder + Reverse

BFS / Kahn:
    Cycle -> result.size() != V
    Order -> indegree == 0 first
==================================================
*/

// =================================================
// 1. DFS TOPOLOGICAL SORT
// =================================================

/*
Algorithm:
1. DFS from every unvisited vertex.
2. state = 0 -> Unvisited
   state = 1 -> Visiting (recursion stack)
   state = 2 -> Visited
3. state == 1 while traversing -> cycle.
4. Add vertex after processing neighbours.
5. Reverse result.

Cycle detection:
    Edge to a "Visiting" node = back edge = cycle.
*/

bool dfs(vector<vector<int>>& graph,
         int cur,
         vector<int>& state,
         vector<int>& result) {

    state[cur] = 1; // Visiting

    for (int neighbour : graph[cur]) {

        if (state[neighbour] == 1)
            return true; // Cycle

        if (state[neighbour] == 0 &&
            dfs(graph, neighbour, state, result))
            return true;
    }

    state[cur] = 2; // Visited
    result.push_back(cur); // Postorder

    return false;
}

vector<int> topoSortDFS(int n, vector<vector<int>>& edges) {

    vector<vector<int>> graph(n);

    for (auto& edge : edges)
        graph[edge[0]].push_back(edge[1]);

    vector<int> state(n, 0);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (dfs(graph, i, state, result))
                return {}; // Cycle -> no topo order
        }
    }

    reverse(result.begin(), result.end());

    return result;
}


// =================================================
// 2. BFS — KAHN'S ALGORITHM
// =================================================

/*
Algorithm:
1. Calculate indegree of every vertex.
2. Push all indegree == 0 vertices into queue, since they have no dependency.
3. Pop queue vertex and add to result.
4. Reduce indegree of its neighbours.
5. If neighbour becomes 0 -> push it.

Cycle detection:
    If result.size() != V -> cycle exists.

Why?
A cycle never produces a vertex with indegree 0.

Time:  O(V + E)
Space: O(V)
*/

vector<int> topoSortBFS(int n, vector<vector<int>>& edges) {

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }

    queue<int> q;

    // Start with vertices having no prerequisites
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> result;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push_back(cur);

        for (int neighbour : graph[cur]) {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    // Not all vertices processed -> cycle
    if (result.size() != n)
        return {};

    return result;
}


// =================================================
// EXAMPLE
// =================================================

int main() {

    int n = 4;

    // Directed edges: u -> v
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3}
    };

    vector<int> dfsResult = topoSortDFS(n, edges);
    vector<int> bfsResult = topoSortBFS(n, edges);

    cout << "DFS: ";
    for (int x : dfsResult)
        cout << x << " ";

    cout << "\nBFS: ";
    for (int x : bfsResult)
        cout << x << " ";

    return 0;
}
