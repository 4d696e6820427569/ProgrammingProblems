/**
 * EPI Chapter 6
 *
 * 6.1 The Dutch national flag problem
 *
 * Write a program that takes an array A and an index i into A, and rearranges
 * the elements such that all elements less than A[i] (the "pivot") appear
 * first, followed by elements equal to the pivot, followed by elements greater
 * than the pivot.
 *
 * Simplest solution is to sort the array, this will take O(nlogn). But
 * a valid partitioning of the array does not have to be sorted. There's also
 * another solution which uses another auxillary array, but this results
 * in O(n) space and O(n) time.
 *
 * There is a linear time solution with constaint space.
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using std::vector;

void print_vect(const vector<int>& v)
{
    for (const auto& e : v)
        printf("%d ", e);
    printf("\n");
}

void dutch_rearrange(vector<int>& v, size_t pivot_index)
{
    int pivot = v[pivot_index];
    size_t smaller = 0;
    // Group the smaller elements to the left (beginning) of the pivot.
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] < pivot) {
            std::swap(v[i], v[smaller++]);
        }
    }

    // Group the larger elements to the end of the array.
    size_t larger = v.size() - 1;
    for (int i = v.size() - 1; i >= 0 && v[i] >= pivot; i--) {
        if (v[i] > pivot) {
            std::swap(v[i], v[larger--]);
        }
    }

}

int main()
{
    vector<int> tc1 {0, 1, 2, 0, 2, 1, 1};
    dutch_rearrange(tc1, 3);
    print_vect(tc1);

    vector<int> tc2 {0, 1, 2, 0, 2, 1, 1};
    dutch_rearrange(tc2, 2);
    print_vect(tc2);
    return 0;
}
