/*
===============================================================================
                    DFS ON A MATRIX / GRID
===============================================================================

ALGORITHM:
    DFS (Depth-First Search) on a matrix explores all connected cells starting from a given cell.

    For each cell:
        1. Check if the cell is within the matrix boundaries.
        2. Check if the cell is valid / unvisited.
        3. Mark it as visited.
        4. Recursively visit its neighbouring cells.

    DIRS defines the directions in which we can move.

TIME:
    O(N x M): Where N = number of rows; M = number of columns

SPACE:
    O(N x M) auxiliary space in the worst case due to the recursive call stack.
    If counting only the DFS stack: O(N x M)

===============================================================================
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;


// -----------------------------------------------------------------------------
// DFS ON MATRIX
// -----------------------------------------------------------------------------

const int DIRS[4][2] = {
    {0, -1},   // Left
    {-1, 0},   // Up
    {1, 0},    // Down
    {0, 1}     // Right
};


void dfs(vector<vector<int>>& matrix, int i, int j) {

    const int n = matrix.size();
    const int m = matrix[0].size();

    // Out of bounds or already visited / invalid cell
    if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] != 1)
        return;

    // Mark current cell as visited
    matrix[i][j] = 2;

    // Visit all 4 neighbouring cells
    for (auto [di, dj] : DIRS)
        dfs(matrix, i + di, j + dj);
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

    // Start DFS from (0, 0) and mark all cells as visited
    dfs(matrix, 0, 0);

    return 0;
}