/**
 * The Daily Byte 05/29/2021
 *
 * Given a string, return the index of its first unique character. If a unique
 * character does not exist, return -1.
 */

#include <string>
#include <cassert>
#include <unordered_map>

using std::string;
using std::unordered_map;

int first_unique_character(const string &s)
{
    unordered_map<char, int> m;
    size_t n = s.size();
    for (size_t i = 0; i < n; i++) {
        if (m.find(s[i]) != m.end()) m[s[i]]++;
        else m[s[i]] = 1;
    }

    for (size_t i = 0; i < n; i++) {
        if (m[s[i]] == 1) return i;
    }

    return -1;
}

int main()
{
    string tc1("abcabd");
    assert(first_unique_character(tc1) == 2);

    string tc2("thedailybyte");
    assert(first_unique_character(tc2) == 1);

    string tc3("developer");
    assert(first_unique_character(tc3) == 0);

    string tc4("aabbcc");
    assert(first_unique_character(tc4) == -1);
    return 0;
}
