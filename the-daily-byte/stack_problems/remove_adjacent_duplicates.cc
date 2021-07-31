/**
 * The Daily Byte 06/14/2021
 *
 * Given a string s containing only lowercase letters, continously remove
 * adjacent characters that are the same and return the result.
 */

#include <stack>
#include <string>
#include <cassert>
#include <algorithm>

using std::string;
using std::stack;

string remove_adjacent_dups(const string& s)
{
    string res("");
    stack<char> stack_s;

    for (const auto& c : s) {
        if (!stack_s.empty() && stack_s.top() == c) {
            stack_s.pop();
        } else {
            stack_s.push(c);
        }
    }

    while(!stack_s.empty()) {
        res += stack_s.top();
        stack_s.pop();
    }

    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string tc1("abccba");
    string tc1_res("");
    assert(remove_adjacent_dups(tc1) == tc1_res);

    string tc2("foobar");
    string tc2_res("fbar");
    assert(remove_adjacent_dups(tc2) == tc2_res);

    string tc3("abccbefggfe");
    string tc3_res("a");
    assert(remove_adjacent_dups(tc3) == tc3_res);
    return 0;
}
