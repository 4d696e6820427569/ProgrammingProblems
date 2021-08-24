/**
 * The Daily Byte
 *
 * Travel to points
 *
 * Given N points on a Cartesian plane, return the minimum time required to
 * visit all points in order that they're given.
 * Note: You start at the first point and can move one unit vertically,
 * horizontally, or diagonally in a single second.
 */

#include <vector>
#include <queue>
#include <array>
#include <set>
#include <cassert>

using std::vector;
using std::queue;
using std::array;
using std::set;

const array<array<int, 2>, 8> kDirections{{
    {0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
}};

int BFS(const vector<int>& p1, const vector<int>& p2)
{
    queue<vector<vector<int>>> q;
    set<vector<int>> visited;

    q.emplace(vector<vector<int>>{p1});
    visited.emplace(p1);

    while (!q.empty()) {
        vector<vector<int>> cur_path = q.front();
        q.pop();

        vector<int>& prev = cur_path.back();

        if (prev == p2) {
            return cur_path.size() == 0 ? 0 : static_cast<int>(cur_path.size()) - 1;
        }

        for (const auto& d : kDirections) {
            vector<int> new_node{prev[0] + d[0], prev[1] + d[1]};
            if (visited.find(new_node) == visited.end()) {
                vector<vector<int>> new_path(cur_path);
                new_path.emplace_back(new_node);
                visited.emplace(new_node);
                q.emplace(new_path);
            }
        }
    }

    return -1;
}

int MinTimeToTravel(const vector<vector<int>>& points_list)
{
    if (points_list.size() <= 1) return 0;
    int count = 0;
    for (size_t i = 1; i < points_list.size(); i++) {
        count += BFS(points_list[i-1], points_list[i]);
    }
    return count;
}

int main()
{
    vector<vector<int>> tc1{
        {0, 0},
        {1, 1},
        {2, 2}
    };
    assert(MinTimeToTravel(tc1) == 2);

    vector<vector<int>> tc2{
        {0, 1},
        {2, 3},
        {4, 0}
    };
    assert(MinTimeToTravel(tc2) == 5);
    return 0;
}
