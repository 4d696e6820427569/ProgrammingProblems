/**
 * The Daily Byte
 *
 * 07/11/2021
 *
 * Given a 2D matrix that represents a gold mine, where each cell's value
 * represents an amount of gold, return the maximum amount of gold you can
 * collect given the following rules:
 *
 * 1. You may start and stop collecting gold from any position.
 * 2. You can never visit a cell tat contains 0 gold.
 * 3. You cannot visit the same cell more than once.
 * 4. From the current cell, you may walk one cell to the left, right, up, or
 * down.
 */

#include <vector>
#include <cassert>
#include <cstdio>
#include <algorithm>

using std::vector;

/**
 * Idea:
 *  For all starting position, perform DFS, collecting gold
 * and setting visited coordinate's gold amount to 0.
 *
 * Time complexity: O(n^2m^2) because for every node, we traverse the
 *  entire graph starting from that node. There are nm nodes.
 * Space complexity: O(nm) because we have nm nodes.
 */
size_t getMaxGold(vector<vector<int>>& map, int x, int y, size_t cur_gold)
{
    int n = static_cast<int>(map.size());
    int m = static_cast<int>(map[0].size());

    if (x < 0 || y < 0 || x >= n || y >= m || map[x][y] == 0) 
        return cur_gold;

    // Take gold from this node and explore other nodes.
    int taken_gold = map[x][y];
    map[x][y] = 0;
    
    int possible_x_coord[4] = {0, -1, 1, 0};
    int possible_y_coord[4] = {1, 0, 0, -1};

    size_t max_gold = cur_gold + taken_gold;
    for (int direction = 0; direction < 4; direction++) {
        max_gold = std::max(max_gold, getMaxGold(map, x + possible_x_coord[direction],
                y + possible_y_coord[direction], cur_gold + taken_gold));
    }

    // Restore the amount of taken gold to explore other options.
    map[x][y] = taken_gold;
    return max_gold;
}

size_t maxGold(vector<vector<int>>& map)
{
    int n = static_cast<int>(map.size());
    int m = static_cast<int>(map[0].size());

    size_t result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result = std::max(result, getMaxGold(map, i, j, 0));
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> tc1{
        {0, 2, 0},
        {8, 6, 3},
        {0, 9, 0}
    };

    assert(maxGold(tc1) == 23);


    vector<vector<int>> tc2{
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };

    assert(maxGold(tc2) == 24);

    vector<vector<int>> tc3{
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };

    assert(maxGold(tc3) == 28);
    return 0;
}
