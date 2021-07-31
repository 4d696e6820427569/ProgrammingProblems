/**
 * EPI 06/23/2021 - Chapter 07
 *
 * A string is a sequence of characters. A string may encode an integer, e.g.,
 * "123" encodes 123. In this problem, you are to implement methods that take a
 * string representing an integer and return the corresponding integer, and vice
 * versa. Your code should handle negative integers. You can't use library
 * functions like stoi in C++ and parseInt in Java.
 *
 * Hint: Build the result one digit at a time.
 */

#include <string>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

using std::string;


/**
 * Assumption: s is a legal int representation.
 */
int str_to_int(const string& s)
{
    int n = static_cast<int>(s.size());

    if (n == 1) { return s[0] - '0'; }

    int res = 0;
    if (s[0] == '-') {
        for (int i = 1; i < n; i++) {
            res = res * 10 + (s[i] - '0');
        }
        res = -res;
    } else {
        for (int i = 0; i < n; i++) {
            res = res * 10 + (s[i] - '0');
        }
    }
    return res;
}

string int_to_str(const int& n)
{
    int abs_n = abs(n);
    string res("");

    while (abs_n) {
        res.push_back(abs_n % 10 + '0');
        abs_n /= 10;
    }

    if (n < 0) {
        res.push_back('-');
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    // Test case 1.
    int tc1 = 123;
    string tc1_s("123");
    assert(str_to_int(tc1_s) == tc1);
    assert(int_to_str(tc1) == tc1_s);

    // Test case 2.
    int tc2 = 9;
    string tc2_s("9");
    assert(str_to_int(tc2_s) == tc2);
    assert(int_to_str(tc2) == tc2_s);

    // Test case 3.
    int tc3 = -1245;
    string tc3_s("-1245");
    assert(str_to_int(tc3_s) == tc3);
    assert(int_to_str(tc3) == tc3_s);

    return 0;
}
