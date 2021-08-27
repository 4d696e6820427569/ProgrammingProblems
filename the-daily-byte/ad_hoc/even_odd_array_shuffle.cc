/**
 * The Daily Byte
 *
 * Given an array of integers, sort the array in any manner such that when i is
 * even, nums[i] is even and when i is odd, nums[i] is odd.
 */

#include <cassert>
#include <vector>

using std::vector;

/**
 * BF solution: Create another array and do the simulation.
 *
 * Now, can we do it in place without allocating a new array?
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
void EvenOddShuffleBF(vector<int>& arr)
{
    vector<int> res(arr.size(), 0);

    int even_idx = 0;
    int odd_idx = 1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            res[even_idx] = arr[i];
            even_idx += 2;
        } else {
            res[odd_idx] = arr[i];
            odd_idx += 2;
        }
    }
    arr = res;
}

/**
 * {4, 4, 4, 4, 3, 3, 3}
 *
 * {4, 3, 4, 3, 4, 3, 4}
 */
int main()
{
    vector<int> tc1{1, 2, 3, 4};
    vector<int> tc1_res{2, 1, 4, 3};
    EvenOddShuffleBF(tc1);
    assert(tc1 == tc1_res);
    return 0;
}
