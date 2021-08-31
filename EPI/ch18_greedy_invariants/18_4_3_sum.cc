/**
 * EPI Chapter 18 - Greedy algorithms
 *
 * 18.4 The 3-sum problem
 *
 * Design an algorithm that takes as input an array and a number, and
 * determines if there are 3 entries in the array (not necessarily distinct)
 * which add up to the specified number. For example, if the array is
 * {11, 2, 5, 7, 3} thn there are 3 entries in the array which add up to
 * 21 (3, 7, 11, and 5, 5, 11) (Note that we can use 5 twice, since the problem
 * statement said we can use the same entry more than once.) However, no three
 * entries add up to 22.
 *
 * Hint: How would you check if a given array entry can be added to 2 more
 * entries to get the specified number?
 */

#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>

using std::vector;
using std::sort;

/**
 * Idea: Given a sorted array and an integer, returns true if there are 2
 * elements that sum to that integer.
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
bool HasTwoSum(vector<int>& A, int s)
{
    int lower = 0, upper = static_cast<int>(A.size()) - 1;
    while (lower < upper) {
        int cur_sum = A[lower] + A[upper];
        if (cur_sum == s) {
            return true;
        } else if (cur_sum < s) {
            // Increase the lower element.
            lower++;
        } else {
            // cur_sum > s.
            upper--;
        }
    }

    return false;
}

bool HasThreeSum(vector<int>& A, int s)
{
    sort(A.begin(), A.end());
    for (const auto& e : A) {
        if (HasTwoSum(A, s-e))
            return true;
    }

    return false;
}

int main()
{
    return 0;
}
