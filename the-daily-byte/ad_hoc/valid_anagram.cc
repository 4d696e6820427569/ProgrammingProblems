/**
 * Given 2 strings, s and t return whether or not s is an anagram of t
 *
 * Note: An anagram is a word formed by reordering the letters of
 * another word.
 */

#include <string>
#include <cassert>
#include <algorithm>

using std::string;

bool is_anagram(string t, string s)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}


int main()
{
    string tc1_s("cat");
    string tc1_t("tac");
    assert(is_anagram(tc1_t, tc1_s));

    string tc2_s("listen");
    string tc2_t("silent");
    assert(is_anagram(tc2_t, tc2_s));

    string tc3_s("program");
    string tc3_t("function");
    assert(!is_anagram(tc3_t, tc3_s));
    return 0;
}
