/**
 * EPI Chapter 16 Recursion
 *
 * 16.7 Generate palindromic decompositions
 *
 * A string is said to be palindromic if it reads the same backwards and
 * forwards. A decomposition of a string is a set of strings whose
 * concatenation is the string. For example, "611116" is palindromic, and
 * "611", "11", "6" is one decomposition for it.
 *
 * Compute all palindromic decompositions of a given string. For example, if
 * the string is "0204451881", then the decomposition "020", "44", "5", "1881"
 * is a palindromic, as is "020", "44", "5", "1", "88", "1". However, "02044",
 * "5", "1881" is not a palindromic decomposition.
 *
 * Hint: Focus on the first palindromic string in a palindromic decomposition.
 */

#include <vector>
#include <string>

using std::string;
using std::vector;

void PrintVector(const vector<string>& v)
{
    for (const auto& e : v) {
        printf("%s\n", e.c_str());
    }
    printf("\n");
}

void PrintMatrix(const vector<vector<string>>& m)
{
    for (const auto& v : m) {
        PrintVector(v);
    }
}

bool isPalindrome(const string& s, int i, int j)
{
    while (i < j) if (s[i++] != s[j--]) return false;
    return true;
}

void directedPalindromicDecomposition(vector<vector<string>>& res,
        vector<string>& cur_list, const string& s, int start)
{
    if (start >= s.size()) { 
        res.emplace_back(cur_list);
    } else {
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                cur_list.emplace_back(s.substr(start, end - start + 1));
                directedPalindromicDecomposition(res, cur_list, s, end + 1);
                cur_list.pop_back();
            }
        }
    }
}

vector<vector<string>> PalindromePartitioning(const string& s)
{
    vector<vector<string>> res;
    vector<string> cur_list;
    directedPalindromicDecomposition(res, cur_list, s, 0);
    return res;
}

int main()
{
    string tc1("aab");
    vector<vector<string>> tc1_res =  PalindromePartitioning(tc1);
    PrintMatrix(tc1_res);
    return 0;
}
