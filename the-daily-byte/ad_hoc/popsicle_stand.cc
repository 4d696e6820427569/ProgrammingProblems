/**
 * The Daily Byte
 *
 * 07/18/2021
 *
 * You're running a popsicle stand where each popsicle costs $5. Each customer
 * you encountered pays with either a $5 bill, a $10 bill, or a $20 bill and
 * only buys a single popsicle. The customers that come to your stand come in
 * the ordered given by the customers array where customers[i] represents the
 * bill the ith customers pays with. Starting with $0, return whether or not
 * you can serve all the given customers while also giving the correct amount
 * of change.
 *
 * LC equivalent: LC 860 Lemonade Change.
 */

#include <vector>
#include <cassert>

using std::vector;

bool possible_change(const vector<int>& bills)
{
    int bill_5 = 0;
    int bill_10 = 0;

    for (const auto& b : bills) {
        if (b == 5) bill_5++;
        if (b == 10) bill_10++;
        if (b - 5 == 15) {
            bill_5--;
            if (bill_10 > 0) bill_10 -= 1;
            else bill_5 -= 2;
        } else if (b - 5 == 5) {
            bill_5 -= 1;
        } else if (b - 5 == 10) {
            bill_10 -= 1;
        }

        if (bill_10 < 0 || bill_5 < 0) return false;
    }
    return true;
}

int main()
{
    vector<int> tc1{5, 5, 5, 10, 20};
    vector<int> tc2{5, 5, 10};
    vector<int> tc3{10, 10};
    vector<int> tc4{5, 5, 10, 10, 20};

    assert(possible_change(tc1));
    assert(possible_change(tc2));
    assert(!possible_change(tc3));
    assert(!possible_change(tc4));

    return 0;
}
