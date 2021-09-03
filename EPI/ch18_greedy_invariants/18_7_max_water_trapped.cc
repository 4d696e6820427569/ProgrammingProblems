/**
 * EPI - Chapter 18 Greedy algorithms
 *
 * 18.7 Compute the maximum water trapped by a pair of vertical lines
 *
 * An array of integers naturally defines a set of lines parallel to the
 * Y-axis, starting from x = 0. The goal of this problem is to find the pair
 * that together with the X-axis "trap" the most water.
 */

#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;
using std::max;
using std::min;

/**
 * BF solution:
 * Consider every possible pair of lines heights[i] and heights[j] such that
 * i < j. Record the maximum area that 2 lines can formed. This area can be
 * calculated by the formula (j - i) * min(heights[i], heights[j]).
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
int GetMaxTrappedWaterBF(const vector<int>& heights)
{
    int max_area = 0;
    for (size_t i = 0; i < heights.size(); i++) {
        for (size_t j = i + 1; j < heights.size(); j++) {
           max_area = max(max_area, 
                   min(heights[i], heights[j]) * (static_cast<int>(j - i)));
        }
    }
    return max_area;
}

/**
 * Idea: First, consider A[0] and A[n-1]. The area is
 * (n - 1) * min(A[0], A[n-1]). There are 3 cases after this
 * 1. A[0] < A[n-1]: If so then for every k < n-1,
 *  k * A[0] < (n - 1) * A[0]
 *
 *  We only need to consider the lines [1, n-1]
 *
 * 2. A[0] == A[n-1], we remove line 0 and line n - 1 from consideration.
 *  and consider the lines [1, n-2]
 *
 * 3. A[0] > A[n-1]: If so then for every k > 0,
 * k * A[n-1] < (n - 1) * A[n-1]
 *
 *  We only need to consider the lines [0, n-2]
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int GetMaxTrappedWater(const vector<int>& heights)
{
    int max_area = 0;
    int i = 0, j = static_cast<int>(heights.size()) - 1;
    while (i < j) {
        max_area = max(max_area, (j - i) * min(heights[i], heights[j]));
        if (heights[i] == heights[j]) {
            i++; j--;
        } else if (heights[i] < heights[j]) {
            i++; 
        } else {
            // heights[i] > heights[j]
            j--;
        }
    }
    return max_area;
}

int main()
{
    vector<int> tc1{1,8,6,2,5,4,8,3,7};
    int tc1_res = 49;
    assert(GetMaxTrappedWater(tc1) == tc1_res);
    assert(GetMaxTrappedWaterBF(tc1) == tc1_res);
    return 0;
}
