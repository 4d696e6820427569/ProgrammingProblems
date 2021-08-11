/**
 * EPI Chapter 17 - Dynamic programming
 *
 * 07/21/2021
 * 17.1 Count the number of score combinations.
 *
 * In an American football game, a play can lead to 2 points (safety), 3 points
 * (field goal), or 7 points (touchdown, assuming extra point). Many different
 * combinations of 2, 3, and 7 points plays can make up a final score. For
 * example, four combinations of plays yield a score of 12:
 * 6 safeties (2 x 6 = 12),
 * 3 safeties and 2 field goals (2 x 3 + 3 x 2 = 12),
 * 1 safety, 1 field goal and 1 touchdown (2 x 1 + 3 x 1 + 7 x 1 = 12), and
 * 4 field goals (3 x 4 = 12)
 *
 * Write a program that takes a final score and scores for individual plays,
 * and returns the number of combinations of plays that result in the final
 * score.
 */

#include <cassert>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

int NumCombinationsForFinalScore(int final_score, const vector<int>& individual_play_scores)
{
    // Assumption: individual_play_scores is sorted from lowest to highest.
    // Base case: dp[ips[0]] = 1, dp[ips[1]] = 1, ...
    //
    // Recurrence formula:
    // dp(n) = dp(n - ips[0]) + dp(n - ips[1]) + ... + dp(n - ips[n-1])
    // dp[0] = 1. Because there's always 1 way to make play to reach the score
    // of 0, which is not make a play at all.
    vector<int> dp(final_score+1, 0);
    dp[0] = 1;
    
    for (const auto& score : individual_play_scores) {
        for (size_t i = 1; i <= final_score; i++) {
            if (i >= score) {
                dp[i] += dp[i-score];
            }
        }
    }

    return dp[final_score];
}

int main()
{
    vector<int> tc1{2, 4, 7};
    printf("%d\n", NumCombinationsForFinalScore(12, tc1));
    assert(NumCombinationsForFinalScore(12, tc1) == 4);
    return 0;
}
