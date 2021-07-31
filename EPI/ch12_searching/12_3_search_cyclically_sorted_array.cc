/**
 * EPI Chapter 12 Searching
 *
 * 12.3 Search a cyclically sorted array.
 *
 * An array is said to be cyclically sorted if it is possible to cyclically
 * shift its entries so that it becomes sorted. For example, the array
 *
 * < 378, 478, 550, 631, 103, 203, 220, 234, 368 >
 *
 * is cyclically sorted - a cyclic left shift by 4 leads to a sorted array.
 *
 * Design an O(logn) algorithm for finding the position of the smallest element
 * in a cylically sorted array. Assume all elements are distinct. For example,
 * for the array above, our algorithm should return 4.
 *
 * Hint: Use divide and conquer.
 */

#include <cstdio>
#include <cassert>
#include <vector>

using std::vector;

int getSmallestIdx(vector<int>& arr)
{
    int left = 0, right = arr.size() - 1;

    while ( left < right ) {
        int m = left + (right - left) / 2;
        if (arr[m] > arr[right]) {
            left = m + 1;
        } else if (arr[m] < arr[right]) {
            right = m;
        }
    }

    return left;
}

int main()
{
    vector<int> tc1{378, 478, 550, 631, 103, 203, 220, 234, 368};
    assert(getSmallestIdx(tc1) == 4);
    return 0;
}
