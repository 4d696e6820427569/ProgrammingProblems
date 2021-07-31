/**
 * EPI Chapter 05
 * 5.8 Reverse Digits
 *
 * Write a program which takes an integer and returns the integer
 * corresponding to the digits of the input written in reverse order.
 * For example, the reverse of 42 is 24, and the reverse of -314 is -413.
 *
 * Hint: How would you solve the same problem if the input is presented
 * as a string?
 */

#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>

using std::string;

/**
 * If we're presented a number as a string
 * Runtime: O(n) where n is the number of digits.
 */
string reverse_digits_str1(string n)
{
    if (n[0] == '-') {
        reverse(begin(n)+1, end(n));
    } else {
        reverse(begin(n), end(n));
    }
    return n;
}

/**
 * Solution without converting to string
 */
int reverse_digits_int1(int n)
{
    // Count the number of digits.
    int n_copy = n;
    int n_digits = 0;
    int res = 0;
    while (n_copy) {
        n_copy /= 10;
        n_digits++;
    }

   bool neg = false;
   if ( n < 0 ) {
       n = -n;
       neg = true;
   }        

    while ( n_digits > 0 ) {
        int cur_digit = n % 10;
        res += cur_digit * pow(10, n_digits-1);
        n /= 10;
        n_digits--;
    }

    if (neg) return -res;
    return res;
}

long reverse_digits_sol(int x)
{
    long result = 0;
    long x_remaining = abs(x);
    while (x_remaining) {
        result = result * 10 + x_remaining % 10;
        x_remaining /= 10;
    }

    return x < 0 ? -result : result;
}

int main()
{
    string tc1_s("42");
    string tc1_sre("24");
    assert(reverse_digits_str1(tc1_s) == tc1_sre);

    string tc2_s("-314");
    string tc2_sre("-413");
    assert(reverse_digits_str1(tc2_s) == tc2_sre);

    int tc1_int = 42;
    assert(reverse_digits_int1(tc1_int) == 24);

    int tc2_int = -314;
    assert(reverse_digits_int1(tc2_int) == -413);
}
