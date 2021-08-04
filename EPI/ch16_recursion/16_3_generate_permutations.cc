/**
 * EPI Chapter 16 Recursion
 *
 * Write a program which takes as input an array of distinct integers and
 * generates all permutations of that array. No permutation of the array
 * may appear more than once.
 */

#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

void PrintMatrix(const vector<vector<int>>& m)
{
    for (const auto& v : m) {
        for (const auto& e: v) {
            printf("%d ", e);
        }
        printf("\n");
    }
    printf("\n");
}

void DirectedPermutations(vector<vector<int>>& res, vector<int>& A, int idx)
{
    if (idx == A.size()) {
        res.emplace_back(A);
    } else {
        for (int i = idx; i < A.size(); i++) {
            std::swap(A[idx], A[i]);
            DirectedPermutations(res, A, idx + 1);
            std::swap(A[idx], A[i]);
        }
    }
}

vector<vector<int>> Permutations(vector<int>& A)
{
    vector<vector<int>> res;
    DirectedPermutations(res, A, 0);
    return res;
}

int main()
{
    vector<int> tc1{2, 3, 5, 7};
    vector<vector<int>> m = Permutations(tc1);
    PrintMatrix(m);
    return 0;
}
