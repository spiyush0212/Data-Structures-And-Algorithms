#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {weight, node}

/*
    PRIM'S ALGORITHM
    ----------------
    Finds the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph.

    IDEA:
    - Start from any vertex.
    - Always pick the cheapest edge that connects the current MST to an unvisited vertex.
    - Use a min-heap to efficiently get the cheapest edge.

    STEPS:
    1. Start from any node.
    2. Push {0, startNode} into the min-heap : {Weight, Node}
    3. Pop the cheapest edge.
    4. If the node is already visited, skip it.
    5. Otherwise, visit the node and add the edge cost.
    6. Push all edges to unvisited neighbours.
    7. Repeat until all vertices are visited.

    WHY VISITED?
    If a popped edge leads to an already visited node, taking it would create a cycle, so we skip it.

    TIME: O(E log V)
    - Each edge can be pushed into the min-heap.
    - Each heap operation costs O(log V).

    SPACE: O(V + E)
    - O(V) for visited array and heap.
    - O(E) for the adjacency list.
*/

int prims(vector<vector<pii>>& graph) {
    int V = graph.size();

    // Min-heap: {edgeWeight, node}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Start from node 0 with cost 0
    pq.push({0, 0});

    vector<bool> visited(V, false);
    int mstCost = 0;

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        // Already part of MST
        if (visited[node])
            continue;

        // Add node to MST
        visited[node] = true;
        mstCost += weight;

        // Consider all edges from this node
        for (auto [neighbour, edgeWeight] : graph[node])
            if (!visited[neighbour])
                pq.push({edgeWeight, neighbour});
    }

    return mstCost;
}

int main() {
    int V = 4;

    vector<vector<pii>> graph(V);

    auto addEdge = [&](int u, int v, int weight) {
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    };

    addEdge(0, 1, 1);
    addEdge(0, 2, 4);
    addEdge(1, 2, 2);
    addEdge(1, 3, 5);
    addEdge(2, 3, 3);

    cout << "MST Cost: " << prims(graph) << endl;

    return 0;
}