/**
 * The Daily Byte
 *
 * 07/16/2021
 *
 * You are given a bag of coins, an initial energy of E, and want to maximize
 * your number of points (which starts at zero). To gain a single point you can
 * exchange coins[i] amount of energy (i.e. if I have 100 energy and a coin
 * that has a value 50, I can exchange 50 energy to gain a point). If you do
 * not have enough energy you can give away a point in exchange for an increase
 * in energy by coins[i] amount (i.e. you give away a point and your energy is
 * increased by the value of that coin: energy += coins[i]). Return the maximum
 * number of points you can gain.
 *
 * Note: Each coin may only be used one.
 *
 * Equivalent: LC948.
 */

#include <vector>
#include <cassert>
#include <algorithm>

using std::vector;
using std::sort;

int bagOfTokensScore(vector<int>& tokens, int power)
{
    sort(tokens.begin(), tokens.end());
    int score = 0, i = 0, j = static_cast<int>(tokens.size() - 1);

    while (i <= j) {
        if (power < tokens[i]) {
            if (score > 0 && i != j) {
                score -= 1;
                power += tokens[j];
                tokens[j] = 0;
                j--;
            } else {
                // Hit a block herem we can't afford anything.
                return score;
            }
        } else if (tokens[i] >= 0) {
            score += 1;
            power -= tokens[i];
            tokens[i] = 0;
            i++;
        }
    }
    return score;
}

int main()
{
    vector<int> tc1{100};
    int tc1_power = 50;
    assert(bagOfTokensScore(tc1, tc1_power) == 0);

    vector<int> tc2{100, 200};
    int tc2_power = 150;
    assert(bagOfTokensScore(tc2, tc2_power) == 1);

    vector<int> tc3{100, 200, 300, 400};
    int tc3_power = 200;
    assert(bagOfTokensScore(tc3, tc3_power) == 2);

    vector<int> tc4{100, 150, 200};
    int tc4_power = 150;
    assert(bagOfTokensScore(tc4, tc4_power) == 1);

    vector<int> tc5{300};
    int tc5_power = 200;
    assert(bagOfTokensScore(tc5, tc5_power) == 0);

    vector<int> tc6{1, 2, 3, 4, 100, 200};
    int tc6_power = 110;
    assert(bagOfTokensScore(tc6, tc6_power) == 5);

    vector<int> tc7{1, 2, 3, 4, 100, 200};
    int tc7_power = 310;
    assert(bagOfTokensScore(tc7, tc7_power) == 6);

    vector<int> tc8{1000, 2000, 3000, 3000};
    int tc8_power = 3000;
    assert(bagOfTokensScore(tc8, tc8_power) == 2);

    vector<int> tc9{83, 67, 0};
    int tc9_power = 49;
    assert(bagOfTokensScore(tc9, tc9_power) == 1);

    vector<int> tc10{68, 85, 34, 25, 60};
    int tc10_power = 44;
    assert(bagOfTokensScore(tc10, tc10_power) == 2);
    return 0;
}
