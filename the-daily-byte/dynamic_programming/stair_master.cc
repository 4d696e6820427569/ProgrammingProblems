/**
 * The Daily Byte
 *
 * 07/23/2021
 * Given a staircase where the ith step has a non-negative cost
 * associated with it given by cost[i], return the minimum cost of
 * climbing to the top of the staircase. You may climb 1 or 2 steps at a
 * time and you may start climbing from either the first or second step.
 *
 * Leet code equivalent: LC746 Min Cost Climbing Stairs
 */

#include <vector>
#include <algorithm>

using std::vector;
using std::min;

/**
 * Bottom up DP
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
int MinCostClimbingStairs(const vector<int>& costs)
{
    vector<int> dp(costs.size() + 1, 0);
    dp[0] = 0; dp[1] = 0;
    for (size_t i = 2; i <= costs.size(); i++)
        dp[i] = min(costs[i-1] + dp[i-1],
                    costs[i-2] + dp[i-2]);
    return dp[costs.size()];
}

int main()
{

    return 0;
}


