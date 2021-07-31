/**
 * The Daily Byte
 *
 * 07/13/2021
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 */

#include <string>
#include <vector>

using std::vector;
using std::string;

void backtrack(vector<string>& ans, string& cur, size_t open, size_t close, size_t max)
{
    if (cur.size() == max * 2) {
        ans.emplace_back(cur);
    } else {
        if (open < max) {
            cur.append("(");
            backtrack(ans, cur, open + 1, close, max);
            cur.pop_back();
        }

        if (close < open) {
            cur.append(")");
            backtrack(ans, cur, open, close + 1, max);
            cur.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s("");
    backtrack(ans, s, 0, 0, n);
    return ans;
}

int main()
{
    return 0;
}
