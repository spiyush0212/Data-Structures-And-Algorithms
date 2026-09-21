/*

Floyd-Warshall:
    All-pairs shortest path
    Supports negative edge weights
    Does NOT support negative cycles

Algorithm:
    1. Create a distance matrix where dist[i][j] is the direct distance from i to j (INF for others, 0 for same node).
    2. Consider every node `via` as a possible intermediate node.
    3. For every pair (i, j), check whether i -> via -> j is shorter than i -> j.
    4. Update: dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]).
    5. After all nodes are considered as `via`, dist contains shortest paths between every pair.

Time:  O(V^3)
Space: O(V^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;

        vector<vector<int>> dist(
            n + 1,
            vector<int>(n + 1, INF)
        );

        // Distance from a node to itself
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;

        // Add direct edges
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Keep minimum for multiple edges
            dist[u][v] = min(dist[u][v], w);
        }

        // Floyd-Warshall
        for (int via = 1; via <= n; via++) {
            for (int i = 1; i <= n; i++) {
                if (dist[i][via] == INF)
                    continue;

                for (int j = 1; j <= n; j++) {
                    if (dist[via][j] == INF)
                        continue;

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][via] + dist[via][j]
                    );
                }
            }
        }

        // Find maximum shortest distance from k
        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[k][i] == INF)
                return -1;

            answer = max(answer, dist[k][i]);
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int n = 4;
    int k = 2;

    Solution solution;

    cout << solution.networkDelayTime(times, n, k) << endl;

    return 0;
}

// Output:
// 2