/**
 * The Daily Byte
 *
 * Count Islands
 * Given a 2D array of integers with ones representing land and zeroes
 * representing water, return the number of islands in the grid. Note: an
 * island is one or more ones surrounded by water connected either vertically
 * or horizontally.
 */

#include <vector>
#include <cstdio>
#include <iostream>
#include <cassert>
#include <array>

using std::vector;
using std::array;

const array<array<int, 2>, 4> kDirections{{{-1, 0}, {1, 0},
                                            {0, -1}, {0, 1}}};

bool IsMoveable(const vector<vector<int>>& grid, int x, int y)
{
    int n = static_cast<int>(grid.size());
    int m = static_cast<int>(grid[0].size());


    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        return false;
    }

    return true;
}

void DFS(vector<vector<int>>& grid, int x, int y)
{
    if (IsMoveable(grid, x, y)) {
        grid[x][y] = 0;

        for (const auto& arr : kDirections) {
            DFS(grid, x + arr[0], y + arr[1]);
        }
    }    
}

int CountIslands(vector<vector<int>>& grid)
{
    int n = static_cast<int>(grid.size());
    int m = static_cast<int>(grid[0].size());

    int islands_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                islands_count++;
                DFS(grid, i, j);
            }
        }
    }

    return islands_count;
}

int main()
{
    vector<vector<int>> tc1{
        {1,1,0,0,0},
        {1,1,0,1,0},
        {1,1,0,0,1}
    };
    int tc1_n = 3;

    vector<vector<int>> tc2{
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,1,0}
    };
    int tc2_n = 4;

    assert(CountIslands(tc1) == tc1_n);
    assert(CountIslands(tc2) == tc2_n);

    return 0;
}
