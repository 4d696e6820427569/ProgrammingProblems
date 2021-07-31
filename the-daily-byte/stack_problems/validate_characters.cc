/**
 * The Daily Byte 09/06/2021
 * Given a string only containing the following characters
 * (, ), {, }, [, and ] return whether or not the opening
 * and closing characters are in a valid order.
 */

#include <stack>
#include <string>
#include <cassert>
#include <cstdio>

using std::stack;
using std::string;

bool valid_characters(const string& str_in)
{
    stack<char> s;

    for(const auto& c : str_in) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else {
            switch(c) {
                case ')':
                    if (s.top() != '(') {
                        return false;
                    } else {
                        s.pop();
                    }
                    break;
                case '}':
                    if (s.top() != '{') {
                        return false;
                    } else {
                        s.pop();
                    }
                    break;
                case ']':
                    if (s.top() != '[') {
                        return false;
                    } else {
                        s.pop();
                    }
                    break;
                default:
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    string tc1("(){}[]");
    assert(valid_characters(tc1));

    string tc2("(({[]}))");
    assert(valid_characters(tc2));

    string tc3("{(})");
    assert(!valid_characters(tc3));
}
