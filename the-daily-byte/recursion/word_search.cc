/**
 */


#include <vector>
#include <string>
#include <cassert>
#include <queue>

using std::vector;
using std::string;
using std::queue;

bool wordIsFormable(vector<vector<char>>& board, const string& word, int i, int j, int idx)
{
    int n = static_cast<int>(board.size());
    int m = static_cast<int>(board[0].size());

    // Base case.
    if (idx >= static_cast<int>(word.size())) return true;

    // Check for boundaries
    if (i < 0 || i == n || j < 0 || j == m || board[i][j] != word[idx])
        return false;

    board[i][j] = '#';

    bool ret = false;

    int row_off_sets[4] = {0, 1, 0, -1};
    int col_off_sets[4] = {1, 0, -1, 0};
    for (int k = 0; k < 4; k++) {
        ret = wordIsFormable(board, word, i + row_off_sets[k], j + col_off_sets[k], idx+1);
        if (ret) break;;
    }


    board[i][j] = word[idx];
    return ret;
}

bool exist(vector<vector<char>>& board, string word)
{
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            if (wordIsFormable(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> tc1{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string tc1_s("ABCCED");

    assert(exist(tc1, tc1_s));

    return 0;
}
