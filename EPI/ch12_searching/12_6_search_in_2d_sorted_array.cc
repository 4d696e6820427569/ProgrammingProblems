/**
 * Search in a 2D sorted array.
 *
 * Call a 2D array sorted if its rows and its columns are nondecreasing.
 *
 * Design an algorithm that takes a 2D sorted array and a number and checks
 * whether that number appears in the array. For example, if the input is the
 * 2D sorted array and the number is 7, the algorithm should return false.
 * If the number is 8 the algorithm should return true.
 *
 * Hint: Eliminate a row or a column per comparison.
 */

#include <vector>

using std::vector;

bool MatrixSearch(const vector<vector<int>>& A, int x)
{
    // Start from the top right corner.
    int row = 0, col = A[0].size() - 1;

    // Keep searching while there are unclassified rows and columns.
    while (row < A.size() && col >= 0) {
        if (A[row][col] == x) {
            return true;
        } else if (A[row][col] < x) {
            // Eliminate this row.
            row++;
        } else {
            // A[row][col] > x.
            // Eliminate this column.
            col--;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> tc{
        {-1, 2, 4, 4, 6},
        {1, 5, 5, 9, 21},
        {3, 6, 6, 9, 22},
        {3, 6, 8, 10, 24},
        {6, 8, 9, 12, 25},
        {8, 10, 12, 13, 40}
    };

    return 0;
}
