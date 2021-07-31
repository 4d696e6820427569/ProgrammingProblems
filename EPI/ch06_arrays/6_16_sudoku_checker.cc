/**
 * EPI Chapter 06 Arrays
 *
 * Sudoku is a popular logic-based combinatorial number placement puzzle.
 * The objective is to fill a 9x9 grid with digits subject to the constraint
 * that each column, each row, and each of the nine 3x3 sub-grids that compose
 * the grid contains unique integers in [1, 9]. The grid is initialized with a
 * partial assignment as shown.
 *
 *
 * Check whether a 9x9 2D array representing a partially completed Sudoku is
 * valid. Specifically, check that no row, column, or 3 x 3 2D subarray
 * contains duplicates. A 0-value in the 2D array indicates that entry is
 * blank; every other entry is in [1, 9].
 *
 * Hint: Directly test the constraints. Use an array to encode sets.
 */

#include <vector>
#include <cassert>
#include <cstdio>
#include <cmath>

using std::vector;

using vii = vector<vector<int>>;
using vi = vector<int>;

bool is_valid_sudoku(const vii& board)
{
    // Check for rows
    int n = board.size();
    for (int i = 0; i < n; i++) {
        vi table(10, 0);
        for (int j = 0; j < n; j++) {
            table[board[i][j]]++;
            if (board[i][j] != 0 && table[board[i][j]] > 1) {
                printf("Fails rows check: %d\t%d\n", board[i][j], table[board[i][j]]);
                return false;
            }
        }
    }

    // Check for columns
    for (int i = 0; i < n; i++) {
        vi table(10, 0);
        for (int j = 0; j < n; j++) {
            table[board[j][i]]++;
            if (board[j][i] != 0 && table[board[j][i]] > 1) {
                printf("Fails column check: %d\t%d\n", board[j][i], table[board[j][i]] );
                return false;
            }
        }
    }

    // Check for 3x3 2D subarray.
    int sub_size = sqrt(board.size());
    for (int i = 0; i < n; i += sub_size) {
        for (int j = 0; j < n; j += sub_size) {
            vi table(10, 0);
            for (int k = 0; k < sub_size; k++) {
                for (int l = 0; l < sub_size; l++) {
                    table[board[i+k][j+l]]++;
                    if (board[i+k][j+l] != 0 && table[board[i+k][j+l]] > 1) {
                        printf("Fails 3x3 check: %d\t%d\n", 
                                board[i+k][j+l], table[board[i+k][j+l]] );
                        printf("At coordinate: %d, %d\n", i+k, j+l);
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vii tc1 {
        {3, 4, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    assert(is_valid_sudoku(tc1));
    return 0;
}
