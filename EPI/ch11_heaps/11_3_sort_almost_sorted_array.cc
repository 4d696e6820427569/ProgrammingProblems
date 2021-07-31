/**
 * EPI Chapter 11 Heaps
 *
 * 11.3 Sort an almost-sorted array.
 * Often data is almost-sorted. For example, a server receives timestamped
 * stock quotes and earlier quotes may arrive slightly after later quotes
 * because of differences in server loads and network routes. In this problem
 * we address efficient ways to sort such data.
 *
 * Write a program which takes as input a very long sequence of numbers and
 * prints the numbers in sorted order. Each number is at most k away from its
 * correctly sorted position. (Such an array is sometimes referred to as being
 * k-sorted.) Forexample, no number in the sequence <3, -1, 2, 6, 4, 5, 8>
 * is more than 2 away from its final sorted position.
 *
 * Hint:
 */

#include <cassert>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

/**
 * Time complexity: O(nlogk)
 * Space complexity: O(k)
 */
vector<int> SortAlmostSortedArray(vector<int>& input_arr, int k)
{
    priority_queue<int, vector<int>, std::greater<>> min_heap;
    vector<int> res;
    for (const auto& e : input_arr) {
        if (min_heap.size() == k) {
            res.emplace_back(min_heap.top());
            min_heap.pop();
        }
        min_heap.emplace(e);
    }

    while (!min_heap.empty()) {
        res.emplace_back(min_heap.top());
        min_heap.pop();
    }

    return res;
}

int main()
{
    vector<int> tc1{3, -1, 2, 6, 4, 5, 8};
    int tc1_k = 2;
    vector<int> tc1_res{-1, 2, 3, 4, 5, 6, 8};
    assert(tc1_res == SortAlmostSortedArray(tc1, tc1_k));
    return 0;
}
