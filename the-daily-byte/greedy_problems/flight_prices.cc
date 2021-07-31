/**
 * The Daily Byte
 *
 * 07/20/2021
 * A company is booking a flights to send its employees to its 2 satellite
 * offices A and B. The cost of sending the ith employee to office A and
 * office B. The cost of sending the ith employee to office A and office B
 * is given by prices[i][0] and prices[i][1] respectively. Given that half
 * the employees must be sent to office A and half the employees must be sent
 * to office B, return the minimum cost the company must pay for all their
 * employees' flights.
 *
 * LC equivalent: LC 1029.
 */

#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;
using std::sort;

/**
 * Idea: Sort the array based on the amount of money the company would
 * lost i.e. the difference between 2 prices.
 *
 * Time complexity: O(nlogn) due to sorting.
 * Space complexity: O(1).
 */
int MinimumFlightPrices(vector<vector<int>>& prices)
{
    sort(prices.begin(), prices.end(), [](const vector<int>& p1, 
                const vector<int>&p2)
    {
        return p1[0] - p1[1] < p2[0] - p2[1];
    });

    int min_cost = 0;
    for (size_t i = 0; i < prices.size() / 2; i++)
        min_cost += prices[i][0];

    for (size_t i = prices.size() / 2; i < prices.size(); i++)
        min_cost += prices[i][1];

    return min_cost;
}

int main()
{
    vector<vector<int>> tc1 {
        {10, 20}, {30, 200}, {400, 50}, {30, 20}
    };
    assert(MinimumFlightPrices(tc1) == 110);

    vector<vector<int>> tc2 {
        {259, 770}, {448, 54}, {926, 667}, {184, 139},
            {840, 118}, {577, 469}
    };
    assert(MinimumFlightPrices(tc2) == 1859);

    vector<vector<int>> tc3 {
        {515, 563}, {451, 713}, {537, 709}, {343, 819},
            {855, 779}, {457, 60}, {650, 359}, {631, 42}
    };
    assert(MinimumFlightPrices(tc3) == 3086);

    vector<vector<int>> tc4 {
        {40, 30}, {300, 200}, {50, 50}, {30, 60}
    };
    assert(MinimumFlightPrices(tc4) == 310);
    return 0;
}
