/*
===============================================================================
                    BFS ON A MATRIX / GRID
===============================================================================

ALGORITHM:
    BFS (Breadth-First Search) on a matrix explores all connected cells level-by-level starting from a given cell.

    For each cell:
        1. Check its valid neighbouring cells.
        2. Mark a cell as visited when adding it to the queue.
        3. Add its valid neighbours to the queue.
        4. Continue until the queue becomes empty.

    A queue is used to maintain the BFS order.

    DIRS defines the directions in which we can move.

TIME:
    O(N x M): Where N = number of rows; M = number of columns

SPACE:
    O(N x M): Auxiliary space in the worst case for the queue.

===============================================================================
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// -----------------------------------------------------------------------------
// BFS ON MATRIX
// -----------------------------------------------------------------------------

const int DIRS[4][2] = {
    {0, -1},   // Left
    {-1, 0},   // Up
    {1, 0},    // Down
    {0, 1}     // Right
};

void bfs(vector<vector<int>>& matrix, int i, int j) {
    const int n = matrix.size();
    const int m = matrix[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    // Mark as visited when adding to the queue
    matrix[i][j] = 2;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : DIRS) {
            int R = r + dr;
            int C = c + dc;

            if (R >= 0 && R < n && C >= 0 && C < m && matrix[R][C] == 1) {
                q.push({R, C});
                // Mark as visited
                matrix[R][C] = 2;
            }
        }
    }
}

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------

int main() {

    vector<vector<int>> matrix = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    // Start BFS from (0, 0) and mark all 1 neighbours as visited
    bfs(matrix, 0, 0);

    return 0;
}