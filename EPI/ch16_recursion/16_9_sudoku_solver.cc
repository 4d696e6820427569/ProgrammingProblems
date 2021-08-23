/**
 * EPI Chapter 16 Recursion
 *
 * 16.9 Implement a Sudoku solver.
 *
 * Implement a Sudoku solver.
 *
 * Hint: Apply the constraints to speed up a brute-force algorithms.
 */

#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;

void PrintVector(const vector<int>& v)
{
    for (const auto& e : v) {
        printf("%d ", e);
    }
    printf("\n");
}

void PrintMatrix(const vector<vector<int>>& m)
{
    for (const auto& v : m) {
        PrintVector(v);
    }
}

bool isValidPlacement(const vector<vector<int>>& board, const int& n,
        int row, int col, int num)
{
    // Check rows and columns.
    for (int k = 0; k < n; k++) {
        if (board[k][col] == num || board[row][k] == num)
            return false;
    }

    // Check for 3x3 regions.
    int rn = static_cast<int>(sqrt(n));
    int start_x = (row / rn) * rn;
    int start_y = (col / rn) * rn;

    for (int i = start_x; i < start_x + rn; i++) {
        for (int j = start_y; j < start_y + rn; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool backtrack(vector<vector<int>>& board, const int& n,
        int row, int col)
{
    if (row == n) {
        // We reached the goals here.
        return true;
    } else {
        // Find the next blank.
        // If we reach the end of this row, move to the next row.
        if (col == n) {
            return backtrack(board, n, row + 1, col);
        }

        // If the current cell is NOT blank, move to the next column.
        if (board[row][col] != 0) {
            return backtrack(board, n, row, col + 1);
        }

        // Try placing 1-9 to this cell.
        for (int i = 1; i <= 9; i++) {
            if (isValidPlacement(board, n, row, col, i)) {
                board[row][col] = i;
                bool isValid = backtrack(board, n, row, col + 1);
                if (isValid) return true;
                // Not valid. We backtrack.
                board[row][col] = 0;
            }
        }

        // Nothing is valid.
        return false;
    }
}

void SudokuSolver(vector<vector<int>>& board)
{
    int n = static_cast<int>(board.size());
    if (backtrack(board, n, 0, 0))
        PrintMatrix(board);
    else printf("No solution.\n");
}

int main()
{
    vector<vector<int>> tc1{
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    SudokuSolver(tc1);
    return 0;
}
