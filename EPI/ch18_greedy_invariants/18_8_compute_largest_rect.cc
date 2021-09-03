/**
 * EPI Chapter 18 - Greedy algorithms
 *
 * 18.8 Compute the largest rectangle under the skyline
 *
 * You are given a sequence of adjacent buildings. Each has unit width and an
 * integer height. These buildings form the skyline of a city. An architect
 * wants to know the area of a largest rectangle contained in this skyline.
 *
 * Let A be an array representing the heights of adjacent buildings of unit
 * width. Design an algorithm to compute the area of the largest rectangle
 * contained in this skyline.
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <cassert>

using std::vector;
using std::stack;
using std::max;
using std::min;

int CalculateLargestRectangleBF(const vector<int>& heights)
{
    int largest_rect = 0;
    return largest_rect;
}
