/**
 * The Daily Byte
 *
 * Given an array of integers, return a new array, such that each element
 * at index i of the new array is the product of all the numbers in the
 * original array except the one at i.
 *
 * Follow-up: What if you can't use division?
 */

#include <vector>
#include <cassert>

using std::vector;

/**
 * Idea: Multiply all element and then have the total product divided by arr[i]
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
vector<long long> ProductExcept(const vector<int>& arr)
{
    vector<long long> res;
    long long p = 1;
    for (const auto& e : arr)
        p *= e;
    for (size_t i = 0; i < arr.size(); i++) {
        res.emplace_back(p / arr[i]);
    }
    return res;
}

/**
 * What if you can't use division?
 *
 * The BF approach would be multiple every other elements in the array except
 * the one that's being considered.
 *
 * Can we do better here?
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
vector<long long> ProductExceptNoDivBF(const vector<int>& arr)
{
    vector<long long> res;
    for (size_t i = 0; i < arr.size(); i++) {
        long long new_elem = 1;
        for (size_t j = 0; j < arr.size(); j++) {
            if (j != i) new_elem *= arr[j];
        }
        res.emplace_back(new_elem);
    }
    return res;
}

int main()
{
    vector<int> tc1{1,2,3,4,5};
    vector<long long> tc1_res{120, 60, 40, 30, 24};
    assert(ProductExcept(tc1) == tc1_res);
    assert(ProductExceptNoDivBF(tc1) == tc1_res);

    vector<int> tc2{3, 2, 1};
    vector<long long> tc2_res{2, 3, 6};
    assert(ProductExcept(tc2) == tc2_res);
    assert(ProductExceptNoDivBF(tc1) == tc1_res);

    return 0;
}
