/**
 * The Daily Byte
 *
 * 07/15/2021
 *
 * A ship is about to set sail and you are responsible for its safety
 * precautions. More specifically, you are responsible for determining
 * how many life rafts to carry onboard. You are given a list of all the
 * passengers' weights and are informed that a single life raft has a maximum
 * capacity of `limit` and can hold at most 2 people. Return the minimum number
 * of life rafts you must take onboard to ensure the safety of all your
 * passengers. Note: You may assume that the maximum weight of any individual
 * is at most `limit`.
 */

#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

int max_life_rafts(vector<int>& people, int limit)
{
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1;
    int max_boats = 0;
    while (i <= j) {
        if (people[i] + people[j] <= limit) {
            i++;
        }
        j--;
        max_boats++;
    }
    return max_boats;
}

int main()
{
    vector<int> tc1{1, 2};
    int tc1_limit = 3;
    assert(max_life_rafts(tc1, tc1_limit) == 1);

    vector<int> tc2{3, 2, 2, 1};
    int tc2_limit = 3;
    assert(max_life_rafts(tc2, tc2_limit) == 3);

    vector<int> tc3{3, 5, 3, 4};
    int tc3_limit = 5;
    assert(max_life_rafts(tc3, tc3_limit) == 4);

    vector<int> tc4{1, 7, 3, 4, 4, 5, 6, 2};
    int tc4_limit = 7;
    assert(max_life_rafts(tc4, tc4_limit) == 5);

    vector<int> tc5{1, 3, 5, 2};
    int tc5_limit = 5;
    assert(max_life_rafts(tc5, tc5_limit) == 3);

    vector<int> tc6{4, 2, 3, 3};
    int tc6_limit = 5;
    assert(max_life_rafts(tc6, tc6_limit) == 3);
    
    return 0;
}
