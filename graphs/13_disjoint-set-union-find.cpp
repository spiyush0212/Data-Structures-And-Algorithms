/*
    UNION-FIND / DISJOINT SET UNION (DSU)

    Purpose:
    - Maintain multiple disjoint sets/components.
    - Check whether two nodes belong to the same component.
    - Merge two different components.

    Core Operations:
    1. findParent(u)
       - Finds the representative/root of u's component.
       - Uses PATH COMPRESSION.

    2. unionBySize(u, v)
       - Merges components using their sizes.
       - Smaller component is attached to the larger component.

    3. unionByRank(u, v)
       - Merges components using their ranks.
       - Smaller-rank tree is attached to the larger-rank tree.
       - If ranks are equal, choose one root and increase its rank.

    Key Idea:
    - If findParent(u) == findParent(v), they are already connected.
    - Otherwise, merge their components.

    Path Compression:
    - Makes nodes point directly to the root after find.
    - Makes future operations faster.

    Complexity:
    - find:  O(α(N)) amortized
    - union: O(α(N)) amortized
    - Space: O(N)
    - α(N) = inverse Ackermann function, practically constant.
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        rank.resize(n, 0);

        // Initially, every node is its own component.
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] == u)
            return u;
        
        return parent[u] = findParent(parent[u]); // PATH COMPRESSION
    }

    bool unionBySize(int u, int v) {
        int pU = findParent(u);
        int pV = findParent(v);

        // Already in the same component.
        if (pU == pV)
            return false;

        // Attach smaller component to larger component.
        if (size[pU] < size[pV]) {
            parent[pU] = pV;
            size[pV] += size[pU];
        } else {
            parent[pV] = pU;
            size[pU] += size[pV];
        }

        return true;
    }

    bool unionByRank(int u, int v) {
        int pU = findParent(u);
        int pV = findParent(v);

        // Already in the same component.
        if (pU == pV)
            return false;

        // Attach smaller-rank tree under larger-rank tree.
        if (rank[pU] < rank[pV]) {
            parent[pU] = pV;
        }
        else if (rank[pU] > rank[pV]) {
            parent[pV] = pU;
        }
        else {
            // Same rank -> choose either root.
            parent[pV] = pU;
            rank[pU]++;
        }

        return true;
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }
};

int main() {
    // ----------------------------------------------------
    // UNION BY SIZE
    // ----------------------------------------------------

    DSU dsuSize(6);

    dsuSize.unionBySize(0, 1);
    dsuSize.unionBySize(1, 2);
    dsuSize.unionBySize(3, 4);

    cout << boolalpha;

    cout << "Using Union By Size:\n";

    cout << "0 and 2 connected: "
         << dsuSize.isConnected(0, 2) << '\n';

    cout << "0 and 3 connected: "
         << dsuSize.isConnected(0, 3) << '\n';

    dsuSize.unionBySize(2, 3);

    cout << "0 and 4 connected after union: "
         << dsuSize.isConnected(0, 4) << '\n';


    // ----------------------------------------------------
    // UNION BY RANK
    // ----------------------------------------------------

    DSU dsuRank(6);

    dsuRank.unionByRank(0, 1);
    dsuRank.unionByRank(1, 2);
    dsuRank.unionByRank(3, 4);

    cout << "\nUsing Union By Rank:\n";

    cout << "0 and 2 connected: "
         << dsuRank.isConnected(0, 2) << '\n';

    cout << "0 and 3 connected: "
         << dsuRank.isConnected(0, 3) << '\n';

    dsuRank.unionByRank(2, 3);

    cout << "0 and 4 connected after union: "
         << dsuRank.isConnected(0, 4) << '\n';

    return 0;
}

/*
Output:

Using Union By Size:
0 and 2 connected: true
0 and 3 connected: false
0 and 4 connected after union: true

Using Union By Rank:
0 and 2 connected: true
0 and 3 connected: false
0 and 4 connected after union: true
*/