/**
 * EPI Chapter 16 EPI Recursion
 *
 * 16.5 Generate all subsets of size k
 *
 * Write a program which computes all size k subsets of {1, 2, ..., n},
 * where k and n are program inputs. For example, if k = 2 and n = 5, then
 * the result is the following:
 *
 * {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5},
 * {4, 5}}
 *
 * Hint: Think of the right function signature.
 */

#include <vector>

using std::vector;

void PrintMatrix(const vector<vector<int>>& m)
{
    for (const auto& v : m) {
        for (const auto& e : v) {
            printf("%d ", e);
        }
        printf("\n");
    }
}

void DirectedGenerateCombinations(vector<vector<int>>& res,
        vector<int>& cur, int start_idx, int n, int k)
{
    if (k == 0) {
        res.emplace_back(cur);
    } else {
        for (int i = start_idx; i <= n; i++) {
            cur.emplace_back(i);
            DirectedGenerateCombinations(res, cur, i + 1, n, k - 1);
            cur.pop_back();
        }
    }
}

vector<vector<int>> Combinations(int n, int k)
{
    vector<vector<int>> res;
    vector<int> cur;
    DirectedGenerateCombinations(res, cur, 1, n, k);
    return res;
}

int main()
{
    int tc1_n = 4, tc1_k = 2;
    PrintMatrix(Combinations(tc1_n, tc1_k));
    return 0;
}
