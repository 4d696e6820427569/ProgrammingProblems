/**
 * The Daily Byte
 *
 * Given an array nums, return whether or not its values are monotonically
 * increasing or monotonically decreasing.
 *
 * Note: An array is monotonically increasing if for all values i <=j,
 * nums[i] <= nums[j]. Similarly an array is monotonically decreasing if for
 * all values i <= j, nums[i] >= nums[j].
 */

#include <vector>
#include <cassert>

using std::vector;

bool IsMonotonic(const vector<int>& arr)
{
    if (arr.size() > 1) {
        bool greater = arr[1] >= arr[0];
        if (greater) {
            for (size_t i = 2; i < arr.size(); i++)
                if (arr[i] < arr[i-1])
                    return false;
        } else {
            for (size_t i = 2; i < arr.size(); i++)
                if (arr[i] > arr[i-1])
                    return false;
        }
    }

    return true;
}

int main()
{
    vector<int> tc1{1,2,3,4,4,5};
    assert(IsMonotonic(tc1));

    vector<int> tc2{7,6,3};
    assert(IsMonotonic(tc2));

    vector<int> tc3{8,4,6};
    assert(!IsMonotonic(tc3));

    return 0;
}
