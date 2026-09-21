// Bellman-Ford Algorithm
//
// Use:
// - Single-source shortest path
// - Works with negative edge weights
// - Can detect negative-weight cycles
//
// Algorithm:
// 1. Initialize array with source distance = 0, others = INF.
// 2. Relax every edge V - 1 times.
// 3. For edge (u -> v, w): dist[v] = min(dist[v], dist[u] + w)
// 4. Skip if dist[u] == INF because u is unreachable.
// 5. One extra pass can detect a negative cycle.
//
// Why V - 1 iterations?
// A shortest simple path can have at most V - 1 edge, because we have V total nodes, so V-1 edges to reach it.
// Each iteration of Bellman Ford Algorithm can propagate the shortest path by one edge.
//
// Time:  O(V * E)
// Space: O(V)
//
// Negative cycle:
// If any distance improves in the V-th iteration, a negative-weight cycle is reachable from the source.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class BellmanFord {
public:
    vector<int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Relax all edges V - 1 times
        for (int i = 0; i < n - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                // Skip unreachable nodes
                if (dist[u] == INT_MAX)
                    continue;
                
                int newDistance = dist[u] + w;
                // Relax node, if possible
                if (newDistance < dist[v])
                    dist[v] = newDistance;
            }
        }

        return dist;
    }
};

int main() {
    int n = 5;

    // {from, to, weight}
    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}
    };

    int src = 0;

    BellmanFord bf;
    vector<int> dist = bf.shortestPath(n, edges, src);

    cout << "Shortest distances from source " << src << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << '\n';
    }

    return 0;
}