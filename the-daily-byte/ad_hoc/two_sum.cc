/**
 * The Daily Byte 05/26/2021
 *
 * Given an array of integers, return whether or not two numbers sum to a
 * given target, k.
 *
 * Note: You may not sum a number with itself.
 */

#include <vector>
#include <cassert>
#include <unordered_set>

using std::vector;
using std::unordered_set;

/**
 * Hash table solution.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
bool has_two_sum(const vector<int> &arr, int k)
{
    unordered_set<int> s;

    size_t n = arr.size();

    for (size_t i = 0; i < n; i++) {
        if (s.find(arr[i]) != s.end()) {
            return true;
        } else {
            s.insert(k - arr[i]);
        }
    }
    return false;

}

/**
 * Brute force solution.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
bool has_two_sumBF(const vector<int>& arr, int k)
{
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == k) return true;
        }
    }
    return false;
}

/**
 * Two pointers method
 *
 * Time complexity: O(nlogn)
 * Space complexity: O(1)
 */
bool has_two_sum_sort(vector<int>& arr, int k)
{
    std::sort(arr.begin(), arr.end());
    int i = 0, j = static_cast<int>(arr.size()) - 1;
    while (i < j) {
        int cur_sum = arr[i] + arr[j];
        if (cur_sum == k) {
            return true;
        } else if (cur_sum < k) {
            i++;
        } else {
            j--;
        }
    }
    return false;
}

int main()
{
    vector<int> tc1 {1, 3, 8, 2};
    int tc1_k = 10;
    assert(has_two_sum(tc1, tc1_k));
    assert(has_two_sumBF(tc1, tc1_k));
    assert(has_two_sum_sort(tc1, tc1_k));

    vector<int> tc2 {3, 9, 13, 7};
    int tc2_k = 8;
    assert(!has_two_sum(tc2, tc2_k));
    assert(!has_two_sumBF(tc2, tc2_k));
    assert(!has_two_sum_sort(tc2, tc2_k));

    vector<int> tc3 {4, 2, 6, 5, 2};
    int tc3_k = 4;
    assert(has_two_sum(tc3, tc3_k));
    assert(has_two_sumBF(tc3, tc3_k));
    assert(has_two_sum_sort(tc3, tc3_k));

    return 0;
}
