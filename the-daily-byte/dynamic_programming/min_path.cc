/**
 * Given an N x M matrix, grid, where each cell in the matrix represents the
 * cost of stepping on the current cell, return the minimum cost to traverse
 * from the top-left hand corner of the matrix to the bottom-right hand corner.
 *
 * Note: You may only move down or right while traversing the grid.
 */

#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using std::vector;
using std::min;

/**
 * Idea: Recurrence relation:
 *  Sol[i][j] = min(sol[i-1][j], sol[i][j-1]) + grid[i][j]
 *
 * Time complexity: O(nm)
 * Space complexity: O(nm)
 */
int MinPath(vector<vector<int>>& grid)
{
    int n = static_cast<int>(grid.size());
    int m = static_cast<int>(grid[0].size());
    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    return dp[n-1][m-1];
}

int main()
{
    vector<vector<int>> tc{
        {1, 1, 3},
        {2, 3, 1},
        {4, 6, 1}
    };

    int tc_res = 7;
    assert(MinPath(tc) == tc_res);
    return 0;
}
