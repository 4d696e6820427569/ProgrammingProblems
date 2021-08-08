/**
 * EPI Chapter 16 Recursion
 *
 * String in which parens are matched are defined by the following 3 rules:
 *
 * - The empty string, "", is a string in which parens are matched.
 * - The addition of a leading left parens and a trailing right parens to a
 *   string in which parens are matched results in a string in which parens
 *   are matched. For example, since "(())()" is a string with matched parens,
 *   so is "((())())".
 * - The concatenation of 2 strings in which parens are matched is itself a
 *   string in which parens are matched. For example, since "(())()" and "()"
 *   are strings with matched parens, so is "(())()()".
 *
 * Write a program that takes as input a number and returns all the strings
 *   with that number of matched pairs of parents.
 *
 *  Hint: Think about what the prefix of a string of matched parens must look like.
 */

#include <vector>
#include <string>
#include <cstdio>

using std::vector;
using std::string;

void PrintVector(const vector<string>& v)
{
    for (const auto& e : v) {
        printf("%s\n", e.c_str());
    }
}

void DirectedGenerateBalancedParentheses(vector<string>& res, 
        int n, string& s, int open, int close)
{
    if (static_cast<int>(s.size()) == n * 2) {
        res.emplace_back(s);
    } else {
        if (open < n) {
            s.append("(");
            DirectedGenerateBalancedParentheses(res, n, s, open + 1, close);
            s.pop_back();
        }

        if (close < open) {
            s.append(")");
            DirectedGenerateBalancedParentheses(res, n, s, open, close + 1);
            s.pop_back();
        }
    }
}

vector<string> GenerateBalancedParentheses(int n)
{
    vector<string> result;
    string s("");
    DirectedGenerateBalancedParentheses(result, n, s, 0, 0);
    return result;
}

int main()
{
    int tc_n = 3;
    vector<string> tc_res{"((()))","(()())","(())()","()(())","()()()"};
    PrintVector(GenerateBalancedParentheses(tc_n));

    return 0;
}
