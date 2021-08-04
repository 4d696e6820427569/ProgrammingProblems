/**
 * Playground for recursion problems.
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::swap;

void PrintMatrix(const vector<vector<int>>& m)
{
    for (const auto& v : m) {
        for (const auto& e : v) {
            printf("%d ", e);
        }
        printf("\n");
    }
    printf("Size: %zu\n", m.size());
}

/// Permutation
void DirectedPermutations(vector<vector<int>>& res, vector<int>& A, int cur_idx)
{
    int n = static_cast<int>(A.size());
    if ( cur_idx == n ) {
        res.emplace_back(A);
    } else {
        for (int i = cur_idx; i < n; i++) {
            swap(A[i], A[cur_idx]);
            DirectedPermutations(res, A, cur_idx + 1);
            swap(A[i], A[cur_idx]);
        }
    }
}

vector<vector<int>> Permutations(vector<int> tc1)
{
    vector<vector<int>> res;
    DirectedPermutations(res, tc1, 0);
    return res;
}

int main()
{
    vector<int> tc1{1, 2, 3, 4};

    PrintMatrix(Permutations(tc1));

    return 0;
}
