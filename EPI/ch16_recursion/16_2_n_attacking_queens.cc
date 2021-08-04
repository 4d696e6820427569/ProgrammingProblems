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

/**
 * My Brute Force solution. TLE due to repeated states.
 */
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



/**
 * Solution from EPI: The idea is to use only a single array to represent
 * the chess board since we place the queens on distinct rows. So now we only
 * need to check for columns and diagonals.
 */
bool IsValidPlacement(const vector<int>& col_placement)
{
    int row_idx = static_cast<int>(col_placement.size() - 1);
    for (int i = 0; i < row_idx; i++) {
        int diff = abs(col_placement[i] - col_placement[row_idx]);

        // diff = 0 means same column.
        // diff = row_idx - i means same diagonal?
        // Because row_idx - i is the row difference and diff here is the
        // column difference. If they are the same then we violate the
        // placement diagonally.
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
    if (col_placements.empty()) return;
    int n = static_cast<int>(col_placements[0].size());
    for (const auto& col_placement : col_placements) {
        vector<string> solution(n, string(n, '.'));
        for (size_t i = 0; i < col_placement.size(); i++) {
            solution[i][col_placement[i]] = 'Q';
        }
        solutions.emplace_back(solution);
    }
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
    vector<vector<string>> tc1_res;
    GenerateSolutions(NQueens(4), tc1_res);
    PrintMatrix(tc1_res);
    return 0;
}
