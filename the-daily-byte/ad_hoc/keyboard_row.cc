/**
 * The Daily Byte
 *
 * Keyboard Row
 *
 * Given a list of words, return all words that require only a single row of
 * a keyboard to type.
 *
 * Note: You may assume that all words only contain lowercase alphabetical
 * characters.
 */

#include <vector>
#include <array>
#include <string>

using std::vector;
using std::array;
using std::string;

const array<string, 3> KeyboardRows{"qwertyuiop", "asdfghjkl", "zxcvbnm"};

vector<string> KeyboardRowStrings(const vector<string>& arr)
{
    vector<string> res;
    for (const auto& s : arr) {
        char first_char_row = 2;
        if (KeyboardRows[0].find(s[0]) != string::npos) {
            first_char_row = 0;
        } else if (KeyboardRows[1].find(s[0]) != string::npos) {
            first_char_row = 1;
        }

        bool sat = true;
        for (size_t i = 1; i < s.size(); i++) {
            if (KeyboardRows[first_char_row].find(s[i]) == string::npos) {
                sat = false;
                break;
            }
        }

        if (sat) res.emplace_back(s);
    }
    return res;
}

int main()
{
    vector<string> tc1{"two", "dad", "cat"};
    vector<string> tc1_res{"two", "dad"};
    assert(KeyboardRowStrings(tc1) == tc1_res);

    vector<string> tc2{"ufo", "xyz", "byte"};
    assert(KeyboardRowStrings(tc2).empty());
    return 0;
}
