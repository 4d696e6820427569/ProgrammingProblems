/**
 * EPI Chapter 09 Stacks And Queues
 *
 * 07/10/2021
 *
 * Test a string over "{,},(,),[,]"
 *
 * A string over "{,},(,),[,]" is said to be well-formed if the different types
 * of brackets match in the correct order.
 *
 * For example:
 * "([]){()}" is well-formed. As is "[()[]{()()}]". However, "{)" and
 * "[()[]{()()" are no well-formed.
 *
 * Write a program that tests if a string made up of the characters ')', ')',
 * '[', ']', '{', and '}' is well-formed.
 */

#include <cassert>
#include <string>
#include <stack>

using std::string;
using std::stack;

/**
 * Idea: Use a FILO data structure to check for the matching recent open bracket.
 *
 * Time complexity: O(n) where n is the length of the string.
 * Space complexity: O(m) ~ O(n) where m is the number of open brackets.
 */
bool isWellFormed(const string& str)
{
    stack<char> s;
    for (const auto& c : str) {
        if (c == '[' || c == '{' || c == '(') {
            s.emplace(c);
        } else if (c == ']') {
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
        } else if (c == ')') {
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
        } else if (c == '}') {
            if (s.empty() || s.top() != '{')
                return false;
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string tc1("([]){()}");
    assert(isWellFormed(tc1));

    string tc2("[()[]{()()}]");
    assert(isWellFormed(tc2));

    string tc3("{)");
    assert(!isWellFormed(tc3));

    string tc4("[()[]{()()");
    assert(!isWellFormed(tc4));

    string tc5("[{}{}{}");
    assert(!isWellFormed(tc5));

    return 0;
}
