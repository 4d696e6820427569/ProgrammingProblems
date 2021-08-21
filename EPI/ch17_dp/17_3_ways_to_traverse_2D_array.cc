/**
 * EPI Chapter 17 - DP
 *
 * 17.3 Count the number of way to traverse a 2D array.
 *
 * In this problem you are to count the number of ways of starting at the
 * top-left corner of a 2D array and getting to the bottom-right corner.
 * ALl moves must either go right or down.
 *
 * Write a program that counts how many ways you can go from the top-left
 * to the bottom-right in a 2D array.
 *
 * Hint: If i > 0 and j > 0, you can get to (i, j) from (i - 1, j) or
 * (j - 1, i)
 */

#include <vector>
#include <array>
#include <cassert>

using std::vector;
using std::array;

/**
 * Idea: The number of ways to get to (i, j) is the sum of ways to get to
 * (i - 1, j) and ways to get to (i, j - 1).
 *
 * Time complexity: O(nm)
 * Space complexity: O(nm)
 */
int WaysToTraverse2DArray(size_t n, size_t m)
{
    vector<vector<int>> dp(n, vector<int>(m, 1));

    for (size_t i = 1; i < n; i++) {
        for (size_t j = 1; j < m; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[n-1][m-1];
}

int main()
{
    array<int, 2> tc1{20, 10};
    assert(WaysToTraverse2DArray(tc1[0], tc1[1]) == 6906900);

    array<int, 2> tc2{14, 15};
    assert(WaysToTraverse2DArray(tc2[0], tc2[1]) == 20058300);
    return 0;
}
