/**
 * EPI Chapter 12 Searching
 *
 * 12.4 Compute the integer square root.
 *
 * Write a program which takes a nonnegative integer and returns the largest
 * integer whose square is less than or equal to the given integer. For
 * example, if the input is 16, return 4; if the input is 300, return 17,
 * since 17^ = 289 < 300 and 18^2 = 324 > 300.
 */

#include <algorithm>
#include <cmath>
#include <cassert>

/**
 * The brute force solution would be take an integer k starting from 0
 * and square it up until k*k <= n
 *
 * Time complexity: O(k) where k = sqrt(n)
 * Space complexity: O(1)
 */
int NaiveIntSqrt(size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (i*i > n)
            return i - 1;
    }
    return -1;
}

int IntSqrt(size_t n)
{
    int i = 0, j = n;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (m*m <= n) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    return i - 1;
}

int main()
{
    int tc1 = 16;
    assert(NaiveIntSqrt(tc1) == 4);
    assert(IntSqrt(tc1) == 4);

    int tc2 = 300;
    assert(NaiveIntSqrt(tc2) == 17);
    assert(IntSqrt(tc2) == 17);
    return 0;
}
