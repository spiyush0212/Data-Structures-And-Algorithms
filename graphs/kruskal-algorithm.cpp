/*
    KRUSKAL'S ALGORITHM

    Assume DisjointSet / DSU already exists with:
        - isConnected(u, v)
        - unionBySize(u, v)

    --------------------------------------------------
    APPROACH:
    --------------------------------------------------

    1. Get all edges of the graph.
    2. Sort edges by increasing weight.
    3. Process edges from smallest to largest.
    4. If u and v are already connected, skip the edge.
    5. Otherwise:
           - Union u and v.
           - Add edge weight to MST cost.
    6. Continue until V - 1 edges are selected.

    --------------------------------------------------
    WHY IT WORKS:
    --------------------------------------------------

    - Always pick the smallest edge that connects two different components.
    - An edge connecting two already-connected nodes would create a cycle, so we skip it.
    - After selecting V - 1 edges, we have an MST.

    --------------------------------------------------
    COMPLEXITY:
    --------------------------------------------------

    V = Number of vertices
    E = Number of edges

    Sorting: O(E log E)
    DSU operations: O(E α(V))
    Overall Time: O(E log E + E α(V)) = O(E log E)

    Space: O(V + E)

    α(V) = inverse Ackermann function, practically O(1).
*/

#include <bits/stdc++.h>
using namespace std;

class Kruskal {

public:
int findMST(int V, vector<vector<int>>& edges) {
        // Assume DisjointSet / DSU already exists.
        DisjointSet ds(V);

        // edges[i] = {weight, u, v}
        // Sort edges by increasing weight.
        sort(edges.begin(), edges.end());

        int mstCost = 0;
        int edgesUsed = 0;

        for (auto& edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];

            // Skip if this edge creates a cycle.
            if (ds.isConnected(u, v))
                continue;

            // Take this edge.
            ds.unionBySize(u, v);

            mstCost += weight;
            edgesUsed++;

            // MST contains exactly V - 1 edges.
            if (edgesUsed == V - 1)
                break;
        }

        return mstCost;
    }
};