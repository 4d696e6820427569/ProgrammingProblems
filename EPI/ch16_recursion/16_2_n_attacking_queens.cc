/**
 * EPI Chapter 16 Recursion
 *
 * 16.2 Generate all nonattacking placements of n-Queens
 *
 * A nonattacking placement of queens is one in which no two queens are in the
 * same row, column, or diagonal.
 *
 * Write a program which returns all distinct nonattacking placements of n
 * queens on an n x n chessboard, where n is an input to the program.
 *
 * Hint: If the first queen is placed at (i, j), where can the remaining
 * queens definitely not be placed?
 */

#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <set>

using std::vector;
using std::string;
using std::set;


void PrintVect(const vector<string>& v)
{
    for (const auto& e : v)
        printf("%s\n", e.c_str());
    printf("\n");
}

void PrintMatrix(const vector<vector<string>>& m)
{
    for (const auto& v : m)
        PrintVect(v);
    printf("\n");
}

bool isAttacked(const vector<string>& conf, int row, int col)
{
    int n = static_cast<int>(conf.size());

    // Check vertical.
    for (int i = 0; i < n; i++)
        if (conf[i][col] == 'Q')
            return true;

    // Check horizontal.
    for (int j = 0; j < n; j++)
        if (conf[row][j] == 'Q')
            return true;

    // Check diagonal
    int d[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int i = 0; i < 4; i++) {
        int k = 1;
        while (row + d[i][0] * k >= 0 && row + d[i][0] * k < n &&
                col + d[i][1] * k >= 0 && col + d[i][1] * k < n) {
            if (conf[row + d[i][0] * k][col + d[i][1] * k] == 'Q')
                return true;
        }
    }

    return false;
}

void backtrack(set<vector<string>>& res, vector<string>& cur_conf, int queens_left)
{
    if (queens_left == 0) {
        res.emplace(cur_conf);
    } else {
        int n = cur_conf.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!isAttacked(cur_conf, i, j)) {
                    cur_conf[i][j] = 'Q';
                    backtrack(res, cur_conf, queens_left-1);
                    cur_conf[i][j] = '.';
                }
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    set<vector<string>> res_set;
    string init_row(n, '.');
    vector<string> conf;
    for (int i = 0; i < n; i++)
        conf.emplace_back(init_row);
    backtrack(res_set, conf, n);
    vector<vector<string>> res(res_set.begin(), res_set.end());
    return res;
}


bool IsValidPlacement(const vector<int>& col_placement)
{
    int row_idx = static_cast<int>(col_placement.size() - 1);
    for (int i = 0; i < row_idx; i++) {
        int diff = abs(col_placement[i] - col_placement[row_idx]);
        if (diff == 0 || diff == row_idx - i)
            return false;
    }
    return true;
}


void SolveNQueensEPI(int n, int row, vector<int>& col_placement, vector<vector<int>>& res)
{
    if (row == n) {
        res.emplace_back(col_placement);
    } else {
        for (int col = 0; col < n; col++) {
            col_placement.emplace_back(col);
            if (IsValidPlacement(col_placement)) {
                SolveNQueensEPI(n, row + 1, col_placement, res);
            }
            col_placement.pop_back();
        }
    }
}

void GenerateSolutions(const vector<vector<int>>& col_placements, 
        vector<vector<string>>& solutions)
{

}

vector<vector<int>> NQueens(int n)
{
    vector<vector<int>> res;
    vector<int> col_placement;
    SolveNQueensEPI(n, 0, col_placement, res);
    return res;
}

int main()
{
    PrintMatrix(solveNQueens(4));
    return 0;
}
