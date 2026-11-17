/*
    Dijkstra's Algorithm — Shortest Path

    Use:
    - Weighted graph
    - All edge weights must be NON-NEGATIVE
    - Find shortest distance from one source

    Idea:
    - Keep shortest known distance for every node.
    - Min-heap always gives the node with the smallest distance.
    - Relax all its neighbors.

    Time: O((V + E) log V)
    - Build adjacency list: O(E)
    - For each edge relaxation may push into min-heap: O(log V)

    Space: O(V + E)
    - Adjacency list: O(V + E)
    - Distance array: O(V)
    - Min-heap: O(E) worst case

    Key:
    Dijkstra = Min-Heap + Relaxation + Non-negative weights
*/

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>; // {distance, node}

vector<int> dijkstra(vector<vector<pii>>& graph, int src) {
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [curDist, node] = pq.top();
        pq.pop();

        if (curDist > dist[node])
            continue;

        for (auto [neighbor, weight] : graph[node]) {
            int newDist = curDist + weight;

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;

    // graph[u] = {v, weight}
    vector<vector<pii>> graph(n);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[2].push_back({1, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    int src = 0;

    vector<int> dist = dijkstra(graph, src);

    for (int i = 0; i < n; i++) {
        cout << "Distance from " << src << " to " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << '\n';
    }

    return 0;
}