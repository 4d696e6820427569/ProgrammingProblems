/**
 * EPI - Chapter 06
 *
 * Write a program which takes as input an array of digits encoding a decimal
 * number D and updates the array to represent the number D + 1. For example,
 * if the input is <1, 2, 9> then you should update the array to <1, 3, 0>.
 * Your algorithm should work even if it is implemented in a language that
 * has finite-precision arithmetic.
 *
 * Hint: Experiment with concrete examples.
 */

#include <vector>
#include <cassert>

using std::vector;

/**
 * Simulate a grade school addition algorithm
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
void increment_int(vector<int>& int_arr)
{
    int n = int_arr.size();
    if (n == 0) return;

    int digit = 0;
    bool carry = false;
    int idx = n - 1;
    digit = int_arr[idx] + 1;
    int_arr[idx--] = digit % 10;
    if (digit == 10) {
        carry = true;
    }

    while (carry && idx >= 0) {
        digit = int_arr[idx] + 1;
        int_arr[idx--] = digit % 10;
        if (digit == 10) {
            carry = true;
        } else {
            carry = false;
        }
    }


    if (carry) int_arr.emplace(int_arr.begin(), 1);
}

int main()
{
    vector<int> tc1{1, 2, 9};
    vector<int> tc1_res{1, 3, 0};
    increment_int(tc1);
    assert(tc1 == tc1_res);

    vector<int> tc2{9, 9, 9};
    vector<int> tc2_res{1, 0, 0, 0};
    increment_int(tc2);
    assert(tc2 == tc2_res);

    return 0;
}
