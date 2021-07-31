/**
 * The Daily Byte 06/14/2021
 *
 * Compare keystrokes. Given 2 strings s and t, which represents a sequence
 * of keystrokes, where # denotes a back space, return whether or not the
 * seuqnece produce the same result.
 */

#include <stack>
#include <string>
#include <cassert>
#include <cstdio>

using std::stack;
using std::string;

bool compare_keystrokes(const string& s, const string& t)
{
    stack<char> stack_s;
    stack<char> stack_t;

    size_t i = 0;
    for (const auto& c : s) {
        printf("Address of c: %p\n", &c);
        printf("Address of s[i]: %p\n", &s[i]);
        if (c == '#' && !stack_s.empty()) stack_s.pop();
        else stack_s.push(c);
        printf("Address of top stack: %p\n", &stack_s.top());
        i++;
    }

    for (const auto& c : t) {
        if (c == '#' && !stack_t.empty()) stack_t.pop();
        else stack_t.push(c);
    }

    while (!stack_s.empty() && !stack_t.empty()) {
        char c_s = stack_s.top();
        char c_t = stack_t.top();
        stack_s.pop();
        stack_t.pop();
        if (c_s != c_t) return false;
    }

    if (!stack_t.empty() || !stack_s.empty()) return false;
    return true;
}

int main()
{
    string tc1_s("ABC#");
    string tc1_t("CD##AB");
    assert(compare_keystrokes(tc1_s, tc1_t));

    string tc2_s("como#put#ter");
    string tc2_t("computer");
    assert(compare_keystrokes(tc2_s, tc2_t));

    string tc3_s("cof#dim#ng");
    string tc3_t("code");
    assert(!compare_keystrokes(tc3_s, tc3_t));
    return 0;
}
