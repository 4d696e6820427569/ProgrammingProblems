/**
 * The Daily Byte
 * 07/08/2021
 *
 * Given a string s consisting of only letters and digits, where we are allowed
 * to transform any letter to uppercase or lowercase, return a list containing
 * all possible permutations of the string.
 */

#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <string>
#include <cctype>

using std::string;
using std::vector;

void PrintVector(const vector<string>& v)
{
    for (const auto& s : v) {
        printf("%s\n", s.c_str());
    }
}

/**
 * We can generate our permutation using recursion.
 *
 *
 * Time complexity: O(n!) where n is the length of the string.
 * Space complexity: O(2^m)
 * Let m be the number of alphanumeric characters. The space complexity is
 * O(2^m)
 */
vector<string> GeneratePermutation(string s)
{
    vector<string> result;
    // Base case: s.size() == 0, return empty list.
    // s.size() == 1. If (isalpha(s[0])) check if it's lower/upper.
    //  Convert it to upper/lower respectively.
    //
    // Inductive case: For s.size() = n, our solution would be
    //  T(s) = T(s[0..n-2]) + T(s[n-1])
    //
    if (s.size() > 1) {
        vector<string> subSol = GeneratePermutation(s.substr(0, s.size()-1));
        if (isalpha(s[s.size() - 1])) {
            for (const auto& ss : subSol) {
                result.emplace_back(ss + static_cast<char>(tolower(s[s.size() - 1])));
                result.emplace_back(ss + static_cast<char>(toupper(s[s.size() - 1])));
            }
        } else {
            for (const auto& ss : subSol) {
                result.emplace_back(ss + s[s.size() - 1]);
            }
        }

    } else if (s.size() == 1) {
        if (isalpha(s[s.size() - 1])) {
            string upper(1, toupper(s[s.size() - 1]));
            string lower(1, tolower(s[s.size() - 1]));
            result.emplace_back(upper);
            result.emplace_back(lower);
        } else {
            string nonalpha(1, s[s.size() - 1]);
            result.emplace_back(nonalpha);
        }
    }

    return result;
}

int main()
{
    // Test case 1.
    string tc1_s = "c7w2";
    size_t tc1_alpha = 2;
    vector<string> tc1_res = GeneratePermutation(tc1_s);
    PrintVector(tc1_res);
    printf("Size: %zu\tAlphas: %zu\n", tc1_res.size(), tc1_alpha);

    // Test case 2.
    string tc2_s = "ad42sdxm24";
    size_t tc2_alpha = 6;
    vector<string> tc2_res = GeneratePermutation(tc2_s);
    PrintVector(tc2_res);
    printf("Size: %zu\tAlphas: %zu\n", tc2_res.size(), tc2_alpha);
    return 0;
}
