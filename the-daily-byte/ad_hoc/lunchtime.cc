/**
 * The Daily Byte
 *
 * 07/19/2021
 *
 * You are serving people in a lunch line and need to ensure each person gets
 * a balanced meal. A balanced meal is a meal where there exists the same
 * number of food items as drink items. Someone is helping you prepare the
 * meals and hands you food items (i.e. F) or a drink item (i.e D) in the order
 * specified by the items string. Return the maximum number of balanced meals
 * you are able to create without being able to modify items.
 *
 * LC equivalent: LC 1221
 */

/**
 * Greedy solution: Use 2 pointers to traverse the string, when we are able
 * to form a balanced meal, increment the counter.
 * The greedy solution doesn't work.
 *
 * FDFFDDFFDD returns 3
 */

#include <string>
#include <cassert>

using std::string;

int max_meals(const string& items)
{
    int res = 0;

    int j = 0, f = 0, d = 0;

    while (j < items.size()) {
        // Open window.
        items[j++] == 'F' ? f++ : d++;

        // Close window.
        if (f == d) {
            res++;
            f = 0;
            d = 0;
        }
    }
    return res;
}

int main()
{
    string tc1("FDFDFD");
    int tc1_res = 3;
    assert(max_meals(tc1) == tc1_res);

    string tc2("FDFFDFDD");
    int tc2_res = 2;
    assert(max_meals(tc2) == tc2_res);

    string tc3("FDFFDDFFDD");
    int tc3_res = 3;
    assert(max_meals(tc3) == tc3_res);

    return 0;
}


