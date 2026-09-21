/*
    MULTI-SOURCE BFS
    ----------------

    1. Push ALL sources into the queue that satisfy a given condition (eg; rotten oranges).
    2. Mark them visited.
    3. Run normal BFS level-by-level.
    4. Each level = 1 unit of distance/time.

    Key idea:
    Finds the minimum distance/time from ANY source.

    Time  : O(V + E)   // Graph
            O(M * N)   // Matrix

    Space : O(V)       // Graph
            O(M * N)   // Matrix
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void multiSourceBFS(const vector<vector<int>>& graph,
                    const vector<int>& sources) {
    int V = graph.size();

    vector<bool> visited(V, false);
    queue<int> q;

    // Add ALL sources initially
    for (int source : sources) {
        visited[source] = true;
        q.push(source);
    }

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : graph[node]) {
                if (visited[neighbor])
                    continue;

                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    /*
        Rotting Oranges example:

        2 1 0
        1 1 1
        0 1 2

        Both 2's are sources as they are rotten.
        Multi-source BFS starts from BOTH simultaneously.
    */

    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1, 6},
        {1, 5},
        {2, 4, 6},
        {3, 5}
    };

    vector<int> sources = {0, 2};

    multiSourceBFS(graph, sources);

    return 0;
}