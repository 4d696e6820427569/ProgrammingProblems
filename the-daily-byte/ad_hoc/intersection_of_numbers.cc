/**
 * The Daily Byte 05/31/2021
 * Given two integer arrays, return their intersection
 * Note: The intersection is the set of elements that are
 * common to both arrays.
 */

#include <cassert>
#include <vector>
#include <set>
#include <iostream>

using std::set;
using std::vector;

vector<int> intersection_of_number(const vector<int>& a, const vector<int>& b)
{
    set<int> intersection;
    set<int> s;
    size_t a_len = a.size();
    size_t b_len = b.size();
    for (size_t i = 0; i < a_len; i++) {
        s.insert(a[i]);
    }

    for (size_t i = 0; i < b_len; i++) {
        if (s.find(b[i]) != s.end() && intersection.find(b[i]) == intersection.end())
            intersection.insert(b[i]);
    }

    vector<int> result;
    for (const auto e : intersection) {
        result.push_back(e);
    }
    
    return result;
}

int main()
{
    vector<int> tc1_a {2, 4, 4, 2};
    vector<int> tc1_b {2, 4};
    vector<int> tc1_ans {2, 4};
    assert(intersection_of_number(tc1_a, tc1_b) == tc1_ans);

    vector<int> tc2_a {1, 2, 3, 3};
    vector<int> tc2_b {3, 3};
    vector<int> tc2_ans { 3 };
    assert(intersection_of_number(tc2_a, tc2_b) == tc2_ans);

    vector<int> tc3_a { 2, 4, 6, 8 };
    vector<int> tc3_b { 1, 3, 5, 7 };
    assert(intersection_of_number(tc3_a, tc3_b).empty());
    return 0;

}
