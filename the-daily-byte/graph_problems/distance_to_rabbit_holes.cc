/**
 * Given a 2D array containing only the following values: -1, 0, 1 where -1
 * represents an obstacle, 0 represents a rabbit hole, and 1 represents a
 * rabbit, update every cell containing a rabbit with the distance to its
 * closest rabbit hole.
 *
 * Note: Multiple rabbit may occupy a single rabbit hole and you may assume
 * every rabbit can reach a rabbit hole. A rabbit can only move up, down, left,
 * or right in a single move.
 */

#include <vector>
#include <cassert>
#include <queue>
#include <array>
#include <limits>
#include <iostream>
#include <cstdio>
#include <unordered_set>

using std::vector;
using std::queue;
using std::array;
using std::numeric_limits;
using std::unordered_set;

void PrintVect(const vector<int>& v)
{
    for (const auto& e : v)
        std::cout << e << " ";
    std::cout << "\n";
}

void PrintMatrix(const vector<vector<int>>& m)
{
    for (const auto& v : m)
        PrintVect(v);
    std::cout << "\n";
}

const array<array<int, 2>, 4> kDirections{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

bool IsMoveable(const vector<vector<int>>& graph, int i, int j)
{
    int m = static_cast<int>(graph.size());
    int n = static_cast<int>(graph[0].size());
    return i >= 0 && i < m && j >= 0 && j < n && graph[i][j] != -1;
}

int BFS(vector<vector<int>>& graph, int i, int j)
{
    int m = static_cast<int>(graph.size());

    queue<vector<int>> q;

    unordered_set<int> visited;

    q.emplace(vector<int>{i * m + j});
    visited.emplace(i * m + j);

    while (!q.empty()) {
        vector<int> path = q.front();
        q.pop();

        int cur_i = path.back() / m;
        int cur_j = path.back() % m;

        if (graph[cur_i][cur_j] == 0) {
            return static_cast<int>(path.size());
        }

        for (const auto& d : kDirections) {
            int new_encoded_coordinates = (cur_i + d[0]) * m + (cur_j + d[1]);
            if (visited.find(new_encoded_coordinates) == visited.end() &&
                    IsMoveable(graph, cur_i + d[0], cur_j + d[1])) {
                visited.emplace(new_encoded_coordinates);
                vector<int> new_path{path};
                new_path.emplace_back(new_encoded_coordinates);
                q.emplace(new_path);
            }
        }
    }

    return numeric_limits<int>::max();
}

void FillDistanceRabbitHoles(vector<vector<int>>& graph)
{
    int m = static_cast<int>(graph.size());
    int n = static_cast<int>(graph[0].size());
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                graph[i][j] = BFS(graph, i, j) - 1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> tc1{
        {-1, 0, 1},
        {1, 1, -1},
        {1, 1, 0}
    };

    vector<vector<int>> tc1_res{
        {-1, 0, 1},
        {2, 1, -1},
        {2, 1, 0}
    };

    FillDistanceRabbitHoles(tc1);
    
    PrintMatrix(tc1);
    assert(tc1 == tc1_res);

    vector<vector<int>> tc2{
        {1, 1, 1},
        {1, -1, -1},
        {1, 1, 0}
    };

    vector<vector<int>> tc2_res{
        {4, 5, 6},
        {3, -1, -1},
        {2, 1, 0}
    };

    FillDistanceRabbitHoles(tc2);

    PrintMatrix(tc2);
    assert(tc2 == tc2_res);

    return 0;
}
