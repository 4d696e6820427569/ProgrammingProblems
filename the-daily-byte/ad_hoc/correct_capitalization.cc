/**
 * Daily Byte 05/22/2021
 *
 * Given a string, return whether or not it uses capitalization correctly.
 * A string correctly uses capitalization if all letters are capitalized,
 * no letters are capitalized, or only the first letter is capitalized.
 */

#include <cassert>
#include <cstdio>
#include <string>

bool is_correct_capitalized(const std::string &s)
{
    size_t s_len = s.size();
    if (s_len == 0) return true;

    char first_char = s[0];
    if (first_char >= 'A' && first_char <= 'Z') {
        size_t uncapitalized_counter = 0;
        for (size_t i = 1; i < s_len; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') uncapitalized_counter++;
        }

        if (uncapitalized_counter != 0 && uncapitalized_counter != s_len - 1) return false;
    } else {
        for (size_t i = 1; i < s_len; i++)
            if (s[i] >= 'A' && s[i] <= 'Z') return false;
    }

    return true;
}

int main()
{
    std::string tc1("USA");
    assert(is_correct_capitalized(tc1));

    std::string tc2("Calvin");
    assert(is_correct_capitalized(tc2));

    std::string tc3("compUter");
    assert(!is_correct_capitalized(tc3));

    std::string tc4("coding");
    assert(is_correct_capitalized(tc4));

    std::string tc5("CoDing");
    assert(!is_correct_capitalized(tc5));
}

