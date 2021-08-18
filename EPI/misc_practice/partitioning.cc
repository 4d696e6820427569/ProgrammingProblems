/**
 * Partitioning around a pivot playground.
 */

#include <vector>
#include <cstdio>
#include <iostream>
#include <random>
#include <algorithm>

using std::vector;

template <typename T>
void QuickSortHelper(vector<T>&, long long, long long);

template <typename T>
void PrintVect(const vector<T>& arr)
{
    for (const auto& e : arr) {
        std::cout << e << " ";
    }

    std::cout << "\n";
}

template <typename T>
void QuickSort(vector<T>& arr)
{
   QuickSortHelper(arr, 0, static_cast<long long>(arr.size() - 1)); 
}

template <typename T>
void QuickSortHelper(vector<T>& arr, long long lower, long long upper)
{
    if (lower > upper) return;
    std::default_random_engine gen((std::random_device())());
    size_t pivot_idx = std::uniform_int_distribution<long long>{lower, upper}(gen);
    
    T pivot_value = arr[pivot_idx];
    
    // Move that pivot toward the end of the array.
    std::swap(arr[pivot_idx], arr[upper]);
    long long new_pivot_idx = lower;

    // We find the new pivot index to be inserted in by comparing all elements
    // from [lower, upper)
    for (size_t i = lower; i < upper; i++) {
        if (arr[i] < pivot_value) {
            std::swap(arr[i], arr[new_pivot_idx++]);
        }
    }

    // Get the pivot to its newly found position.
    std::swap(arr[new_pivot_idx], arr[upper]);

    // Perform quick sort on 2 partitions.
    QuickSortHelper(arr, lower, new_pivot_idx - 1);
    QuickSortHelper(arr, new_pivot_idx + 1, upper);
}

int main()
{
    vector<int> tc{4,3,5,6,2,6,7,1,1,7,5,7,6,4,3};
    QuickSort(tc);
    PrintVect(tc);
    return 0;
}
